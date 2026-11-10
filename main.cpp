#include <raylib.h>
#include "includes/Game.h"
#include <filesystem>
#include <iostream>

const int screenWidth = 800;
const int screenHeight = 600;
const int fps = 60;
const Color bgcolor = {0, 0, 0, 255};

int main() {
    InitWindow(screenWidth, screenHeight, "The Apprentice");
    SetTargetFPS(fps);
    std::cout << std::filesystem::current_path() << '\n';
    Game game;
    game.init();
    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(bgcolor);
        game.update();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}