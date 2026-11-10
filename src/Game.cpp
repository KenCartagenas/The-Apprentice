#include <raylib.h>
#include <memory>
#include <iostream>
#include "../includes/component/Button.h"
#include "../includes/component/Background.h"
#include "../includes/Game.h"

void Game::showMainMenu(Vector2 mouseXY) {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        std::string componentClicked = mainMenuRenderer.getComponentClicked(mouseXY);
        std::cout << componentClicked << '\n';
        if (componentClicked=="startbtn")
            startGame = !startGame;
    }
    mainMenuRenderer.drawComponents();
}

void Game::update() {
    Vector2 m = GetMousePosition();
    if (!startGame)
        showMainMenu(m);
}

void Game::init() {
    /*Main Menu*/
    mainMenuRenderer.addComponent(std::make_unique<Background>("../assets/bg.png", "mainMenuBg"));
    mainMenuRenderer.addComponent(std::make_unique<Button>("START", "startbtn", 275, 350, 250, 100, Color({100,100,100,255})));
    mainMenuRenderer.addComponent(std::make_unique<Button>("x", "exitbtn", 10,10,30,30,Color({243,43,53,255})));
}