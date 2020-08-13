#pragma once
#include "Scene.h"
#include "Sprite.h"
#include <list>

class GameScene :
    public Scene
{
private:
    std::list<Sprite*> backgroundList;
public:
    GameScene();
    ~GameScene();

    void Render();
    void Update(float dTime);
};

