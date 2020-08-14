#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "Animation.h"
#include "MainScene.h"
#include <list>

class GameScene :
    public Scene
{
private:
    float gravity;
    bool doubleJump, isJump;

    std::list<Sprite*> backgroundList;
    std::list<Sprite*> bridgeList;
    std::list<Sprite*> obstacleList;
    std::list<Sprite*> coinList;

    Animation* player;
public:
    GameScene();
    ~GameScene();

    void Render();
    void Update(float dTime);
};

