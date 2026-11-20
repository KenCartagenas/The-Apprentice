#include <raylib.h>
#include "includes/Game.h"
#include <stdint.h>
#include <memory>
#include "includes/utilities/TextureHandler.h"
#include "includes/utilities/TextureAsset.h"
const int screenWidth = 800;
const int screenHeight = 600;
const int fps = 60;
const Color bgcolor = {0, 0, 0, 255};

void addAssets(TextureHandler &textureHandler);

int main() {
    InitWindow(0, 0, "The Apprentice");
    SetTargetFPS(fps);
    TextureHandler textureHandler;
    addAssets(textureHandler);
    TextureHandler *textureHandlerPtr = &textureHandler;
    Game game(textureHandlerPtr);
    game.init();
    uint64_t frameCount = 0;
    while(!WindowShouldClose() && !game.shouldClose) {
        frameCount++;
        BeginDrawing();
        ClearBackground(bgcolor);
        game.update(frameCount);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

void addAssets(TextureHandler &textureHandler) {
    textureHandler.addTexture(std::make_unique<TextureAsset>("mainMenuBg", 5, "assets/bg/mainmenu/"));
    textureHandler.addTexture(std::make_unique<TextureAsset>("graySelector", 1, "assets/component/graySelector/"));
    textureHandler.addTexture(std::make_unique<TextureAsset>("redSelector", 1, "assets/component/redSelector/"));
    textureHandler.addTexture(std::make_unique<TextureAsset>("mainMenuLogo", 1, "assets/logo/mainmenu/"));
    textureHandler.addTexture(std::make_unique<TextureAsset>("mapTileset", 1, "assets/map/"));
    textureHandler.addTexture(std::make_unique<TextureAsset>("idle", 9, "assets/character/idle/"));
    textureHandler.addTexture(std::make_unique<TextureAsset>("running", 8, "assets/character/running/"));
}
