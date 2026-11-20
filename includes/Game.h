#pragma once
#include "renderer/Renderer.h"
#include "utilities/TextureHandler.h"
#include "map/Map.h"
#include "player/Player.h"

class Game {
private:
    bool startGame = false;
    int mainMenuChoiceBefore = -1;
    int mainMenuChoice = 0;
    TextureHandler *textureHandlerPtr;
    Renderer mainMenuRenderer;
    Renderer gameMapRenderer;
    Renderer lobbyRenderer;
    Map map;
    Map lobbyMap;
    Player player;
    
public:
    Game(TextureHandler* handler) : 
    textureHandlerPtr(handler), 
    map("map", textureHandlerPtr->getTexture("mapTileset"), Vector2({0, 6})), 
    lobbyMap("lobbyMap", textureHandlerPtr->getTexture("mapTileset"), Vector2 ({0,5})),
    player(
        {0, 5}, 
        {32, 32}, 
        {
            {"idle", textureHandlerPtr->getTexture("idle")},
            {"running", textureHandlerPtr->getTexture("running")}
        }
    ) {}
    bool shouldClose = false;
    void showMainMenu(int frameNumber);
    void update(int frameNumber);
    void init();
};