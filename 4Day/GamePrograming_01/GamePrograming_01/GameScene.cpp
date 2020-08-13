#include "stdafx.h"
#include "GameScene.h"

GameScene::GameScene() {
	gravity = 0;
	isJump = false;
	doubleJump = false;

	backgroundList.push_back(new Sprite("Resources/Sprites/Background.png"));

	Sprite* tmpBackground = new Sprite("Resources/Sprites/Background.png");
	tmpBackground->setPos(SCREEN_WIDTH, 0);
	backgroundList.push_back(tmpBackground);

	tmpBackground = new Sprite("Resources/Sprites/Background.png");
	tmpBackground->setPos(SCREEN_WIDTH * 2, 0);
	backgroundList.push_back(tmpBackground);

	Sprite* tmpbridge = new Sprite("Resources/Sprites/LoopMap.png");
	tmpbridge->setPos(0, 500);
	bridgeList.push_back(tmpbridge);

	tmpbridge = new Sprite("Resources/Sprites/LoopMap.png");
	tmpbridge->setPos(SCREEN_WIDTH, 500);
	bridgeList.push_back(tmpbridge);

	tmpbridge = new Sprite("Resources/Sprites/LoopMap.png");
	tmpbridge->setPos(SCREEN_WIDTH * 2, 500);
	bridgeList.push_back(tmpbridge);

	player = new Animation(10);
	player->AddFrame("Resources/Sprites/player-run.png");
	player->AddFrame("Resources/Sprites/player-stop.png");
	player->setPos(50, 100);
}

GameScene::~GameScene() {

}

void GameScene::Render() {
	for (auto& background : backgroundList) {
		background->Render();
	}

	for (auto& bridge : bridgeList) {
		bridge->Render();
	}

	player->Render();
}

void GameScene::Update(float dTime) {
	Scene::Update(dTime);

	gravity += 9.8f;
	player->setPos(player->getPosX(), player->getPosY() + gravity * dTime);

	if (isJump) {
		player->setPos(player->getPosX(), player->getPosY() - 500 * dTime);

		if (doubleJump) {
			player->setPos(player->getPosX(), player->getPosY() - 300 * dTime);
		}

		if (inputManager->GetKeyState(VK_SPACE) == KEY_DOWN) {
			doubleJump = true;
		}
	}

	if (player->getPosY() > 350) {
		player->setPos(player->getPosX(), 350);
		doubleJump = false;
		isJump = false;
	}

	if (inputManager->GetKeyState(VK_SPACE) == KEY_DOWN) {
		if (player->getPosY() == 350) {
			isJump = true;
			gravity = 0;
		}
	}

	player->Update(dTime);

	int backgroundDiff = 1000 * dTime;
	for (auto iter = backgroundList.begin(); iter != backgroundList.end(); iter++) {
		if ((*iter)->getPosX() < -SCREEN_WIDTH) {
			SAFE_DELETE(*iter);
			iter = backgroundList.erase(iter);

			Sprite* tmpBackground = new Sprite("Resources/Sprites/Background.png");
			tmpBackground->setPos(SCREEN_WIDTH * 2, 0);
			backgroundList.push_back(tmpBackground);

			if (iter == backgroundList.end()) {
				break;
			}
		}

		(*iter)->setPos((*iter)->getPosX() - backgroundDiff, (*iter)->getPosY());
	}

	for (auto iter = bridgeList.begin(); iter !=  bridgeList.end(); iter++) {
		if ((*iter)->getPosX() < -SCREEN_WIDTH) {
			SAFE_DELETE(*iter);
			iter = bridgeList.erase(iter);

			Sprite* tmpbridge = new Sprite("Resources/Sprites/LoopMap.png");
			tmpbridge->setPos(SCREEN_WIDTH * 2, 500);
			bridgeList.push_back(tmpbridge);

			if (iter == bridgeList.end()) {
				break;
			}
		}

		(*iter)->setPos((*iter)->getPosX() - backgroundDiff, (*iter)->getPosY());
	}
}