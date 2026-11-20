#include <raylib.h>
#include <memory>
#include <iostream>
#include "../includes/screen/MainMenu.h"
#include "../includes/screen/GameMap.h"
#include "../includes/screen/Lobby.h"
#include "../includes/Game.h"
#include "../includes/utilities/TextureHandler.h"


void Game::showMainMenu(int frameNumber) {
    std::vector<std::string> options({"loadGameSelector", "startGameSelector", "exitGameSelector"});
    if (IsKeyPressed(KEY_ENTER)) {
        switch (mainMenuChoice) {
            case 1:
                startGame = true;
                break;
            case 2:
                shouldClose = true;
            default:
                break;
        }
    }
    if (IsKeyPressed(KEY_DOWN) && mainMenuChoice < options.size()-1) {
        mainMenuRenderer.setTexture(options[mainMenuChoice], textureHandlerPtr->getTexture("graySelector"));
        mainMenuChoice++;
        mainMenuRenderer.setTexture(options[mainMenuChoice], textureHandlerPtr->getTexture("redSelector"));
    } else if (IsKeyPressed(KEY_UP) && mainMenuChoice > 0) {
        mainMenuRenderer.setTexture(options[mainMenuChoice], textureHandlerPtr->getTexture("graySelector"));
        mainMenuChoice--;
        mainMenuRenderer.setTexture(options[mainMenuChoice], textureHandlerPtr->getTexture("redSelector"));
    }
    mainMenuRenderer.drawComponents(frameNumber);
}

void Game::update(int frameNumber) {
    if (!startGame)
        showMainMenu(frameNumber);
    else {
        //lobbyRenderer.drawComponents(frameNumber);
        Vector2 end = map.getBlockPathEnd(); // In tile coordinates
        Vector2 pos = player.getPosition();  // In tile coordinates

        // Player is 64x64 px = 2x2 tiles
        Rectangle playerRec = { pos.x, pos.y, 2.0f, 2.0f };

        // Exit is 3x1 tiles on top/bottom edges, or 1x3 tiles on left/right edges
        bool isHorizontalEdge = (end.y == 0 || end.y == std::ceil(GetScreenHeight() / 32.0f) - 1);
        Rectangle exitRec = {
            end.x,
            end.y,
            isHorizontalEdge ? 3.0f : 1.0f,
            isHorizontalEdge ? 1.0f : 3.0f
        };

        bool playerAtEnd = CheckCollisionRecs(playerRec, exitRec);
        if (playerAtEnd) {
            map.setBlockPathStart(map.getBlockPathEnd());
            player.setPosition(map.getBlockPathStart());
        }
        gameMapRenderer.drawComponents(frameNumber);
        player.update(frameNumber);
    }
}

void Game::init() {
    Renderer* mainMenuRendererPtr = &mainMenuRenderer;
    Renderer* gameMapRendererPtr = &gameMapRenderer;
    Renderer* lobbyRendererPtr = &lobbyRenderer;
    MainMenu mainMenu(mainMenuRendererPtr, textureHandlerPtr);
    GameMap gameMap(gameMapRendererPtr, textureHandlerPtr);
    Lobby lobby(lobbyRendererPtr, textureHandlerPtr);
    Map* mapptr = &map;
    Map* lobbyMapptr = &lobbyMap;
    mainMenu.initScreen();
    gameMap.initScreen(mapptr);
    lobby.initScreen(lobbyMapptr);
}