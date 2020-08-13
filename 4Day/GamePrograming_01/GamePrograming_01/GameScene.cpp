#include "stdafx.h"
#include "GameScene.h"

GameScene::GameScene() {
	backgroundList.push_back(new Sprite("Resources/Sprites/Background.png"));
}

GameScene::~GameScene() {

}

void GameScene::Render() {
	for (auto& background : backgroundList) {
		background->Render();
	}
}

void GameScene::Update(float dTime) {
	Scene::Update(dTime);
	for (auto iter = backgroundList.begin(); iter != backgroundList.end(); iter++) {
		(*iter)->setPos((*iter)->getPosX() - 500 * dTime, (*iter)->getPosY());

		if ((*iter)->getPosX() < -SCREEN_WIDTH) {
			SAFE_DELETE(*iter);
			iter = backgroundList.erase(iter);
			if (iter == backgroundList.end()) {
				break;
			}
		}
	}
}