#pragma once
#include "renderer/Renderer.h"
#include "utilities/TextureHandler.h"

class Game {
private:
    bool startGame = false;
    int mainMenuChoiceBefore = -1;
    int mainMenuChoice = 0;
    TextureHandler *textureHandlerPtr;
    Renderer mainMenuRenderer;
    Renderer gameMapRenderer;
    
public:
    bool shouldClose = false;
    void showMainMenu(Vector2 mouseXY, int frameNumber);
    void update(int frameNumber);
    void init(TextureHandler *handler);
};