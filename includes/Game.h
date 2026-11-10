#pragma once
#include "renderer/Renderer.h"

class Game {
private:
    bool startGame = false;
    
public:
    Renderer mainMenuRenderer;
    void showMainMenu(Vector2 mouseXY);
    void update();
    void init();
};