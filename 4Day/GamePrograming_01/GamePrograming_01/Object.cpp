#include "stdafx.h"
#include "Object.h"

Object::Object() {
	pos = D3DXVECTOR2(0, 0);

	rotationCenter = D3DXVECTOR2(0, 0);
	scalingCenter = D3DXVECTOR2(0, 0);

	rotation = 0;
	scale = D3DXVECTOR2(1, 1);

	D3DXMatrixIdentity(&mat);

	rect.top = 0;
	rect.left = 0;
	rect.right = 0;
	rect.bottom = 0;

	parent = nullptr;
}

Object::~Object() {
	for (auto& child : childList) {
		SAFE_DELETE(child);
	}
}

void Object::Render() {
	D3DXMatrixTransformation2D(&mat, &scalingCenter, 0, &scale, &rotationCenter, rotation, &pos);

	if (parent != nullptr) {
		mat *= parent->mat;
	}
}

void Object::Update(float dTime) {
	for (auto& child : childList) {
		child->Update(dTime);
	}
}

void Object::AddChild(Object* child) {
	childList.push_back(child);
	child->parent = this;
}

void Object::RemoveChild(Object* object) {
	childList.remove(object);
	object->parent = nullptr;
}

bool Object::IsCollisionRect(Object* object) {
	RECT r, r1 = rect, r2 = object->getRect();

	r1.left += (LONG)pos.x;
	r1.right += (LONG)pos.x;
	r1.top += (LONG)pos.y;
	r1.bottom += (LONG)pos.y;

	r2.left += (LONG)object->getPos().x;
	r2.right += (LONG)object->getPos().x;
	r2.top += (LONG)object->getPos().y;
	r2.bottom += (LONG)object->getPos().y;

	return IntersectRect(&r, &r1, &r2);
}

bool Object::IsPointInRect(D3DXVECTOR2 pt) {
	return (pt.x > rect.left + pos.x && pt.x < rect.right + pos.x && pt.y > rect.top + pos.y && pt.y < rect.bottom + pos.y);
}

D3DXMATRIX Object::getMat() {
	return mat;
}

D3DXVECTOR2 Object::getPos() {
	return pos;
}

RECT Object::getRect() {
	return rect;
}

int Object::getPosX() {
	return (int)pos.x;
}

int Object::getPosY() {
	return (int)pos.y;
}

void Object::setParent(Object* object) {
	this->parent = object;
}

void Object::setPos(int x, int y) {
	pos.x = (FLOAT)x;
	pos.y = (FLOAT)y;
}

void Object::setPos(D3DXVECTOR2 pos) {
	this->pos = pos;
}