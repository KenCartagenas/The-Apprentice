#pragma once
#include "../renderer/Renderer.h"
#include "../utilities/TextureHandler.h"

class MainMenu {
private:
    Renderer* mainMenuRenderer = nullptr;
    TextureHandler* textureHandler = nullptr;

public:
    MainMenu(Renderer* renderer, TextureHandler* textureHandler) : mainMenuRenderer(renderer) , textureHandler(textureHandler) {}
    void initScreen();
};