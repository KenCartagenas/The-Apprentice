#include <raylib.h>
#include <memory>
#include <iostream>
#include "../includes/screen/MainMenu.h"
#include "../includes/Game.h"
#include "../includes/utilities/TextureHandler.h"
#include "../includes/screen/GameMap.h"

void Game::showMainMenu(Vector2 mouseXY, int frameNumber) {
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
    Vector2 m = GetMousePosition();
    if (!startGame)
        showMainMenu(m, frameNumber);
    else
        gameMapRenderer.drawComponents(frameNumber);
}

void Game::init(TextureHandler* handler) {
    textureHandlerPtr = handler;
    Renderer* mainMenuRendererPtr = &mainMenuRenderer;
    Renderer* gameMapRendererPtr = &gameMapRenderer;
    MainMenu mainMenu(mainMenuRendererPtr, textureHandlerPtr);
    GameMap gameMap(gameMapRendererPtr, textureHandlerPtr);
    mainMenu.initScreen();
    gameMap.initScreen();
}