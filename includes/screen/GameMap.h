#pragma once
#include "../renderer/Renderer.h"
#include "../utilities/TextureHandler.h"

class GameMap {
private:
    Renderer* GameMapRenderer = nullptr;
    TextureHandler* textureHandler = nullptr;

public:
    GameMap(Renderer* renderer, TextureHandler* textureHandler) : GameMapRenderer(renderer) , textureHandler(textureHandler) {}
    void initScreen(Map *mapptr);
};