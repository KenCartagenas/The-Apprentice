#include <raylib.h>
#include "../../includes/screen/MainMenu.h"
#include "../../includes/component/Button.h"
#include "../../includes/component/Background.h"
#include "../../includes/component/Picture.h"

void MainMenu::initScreen() {
    float screenX = GetScreenWidth();
    float startX = 385;
    float btnHeight = 75;
    float gap = 40;

    mainMenuRenderer->addComponent(std::make_unique<Background>("mainMenuBg", 
                                                                textureHandler->getTexture("mainMenuBg") 
                                                            ));
    mainMenuRenderer->addComponent(std::make_unique<Picture>("mainMenuLogo", 
                                                            textureHandler->getTexture("mainMenuLogo"), 
                                                            screenX/2-(677/2), 0, 
                                                            677, 369
                                                        ));
    mainMenuRenderer->addComponent(std::make_unique<Picture>("loadGameSelector",
                                                            textureHandler->getTexture("redSelector"),
                                                            screenX/2-350/2, startX,
                                                            350, btnHeight
                                                        ));
    mainMenuRenderer->addComponent(std::make_unique<Picture>("startGameSelector",
                                                            textureHandler->getTexture("graySelector"),
                                                            screenX/2-350/2, startX+gap+btnHeight,
                                                            350, btnHeight
                                                        ));
    mainMenuRenderer->addComponent(std::make_unique<Picture>("exitGameSelector",
                                                            textureHandler->getTexture("graySelector"),
                                                            screenX/2-350/2, startX+(2*gap)+(2*btnHeight),
                                                            350, btnHeight
                                                        ));
    mainMenuRenderer->addComponent(std::make_unique<Button>("loadbtn", 
                                                            "Load Game", 
                                                            screenX/2-100, startX, 
                                                            200, btnHeight, 
                                                            0.5, 
                                                            Color({0,0,0,0}),
                                                            WHITE
                                                        ));
    mainMenuRenderer->addComponent(std::make_unique<Button>("startbtn", 
                                                            "Start Game", 
                                                            screenX/2-100, startX+gap+btnHeight, 
                                                            200, btnHeight, 
                                                            0.5, 
                                                            Color({0,0,0,0}),
                                                            WHITE
                                                        ));
    mainMenuRenderer->addComponent(std::make_unique<Button>("exitbtn", 
                                                            "Exit Game", 
                                                            screenX/2-100, startX+(2*gap)+(2*btnHeight), 
                                                            200, btnHeight, 
                                                            0.5, 
                                                            Color({0,0,0,0}),
                                                            WHITE
                                                        ));
}