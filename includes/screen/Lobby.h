#pragma once
#include "../renderer/Renderer.h"
#include "../utilities/TextureHandler.h"

class Lobby {
private:
    Renderer* LobbyRenderer = nullptr;
    TextureHandler* textureHandler = nullptr;

public:
    Lobby(Renderer* renderer, TextureHandler* textureHandler) : LobbyRenderer(renderer) , textureHandler(textureHandler) {}
    void initScreen(Map *mapptr);
};