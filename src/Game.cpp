#include <raylib.h>
#include <memory>
#include "../includes/component/Button.h"
#include "../includes/Game.h"

void Game::showMainMenu() {
    mainMenuRenderer.addComponent(std::make_unique<Button>("START", 275, 350, 250, 100, Color({100,100,100,255})));
    mainMenuRenderer.drawComponents();
}

void Game::update() {
    Vector2 m = GetMousePosition();
    if (IsMouseButtonPressed(0) && m.x >= 275 && m.x <= 275+250 && m.y >= 350 && m.y <= 450)
        startGame = !startGame;
    if (!startGame) {
        showMainMenu();
    }
}