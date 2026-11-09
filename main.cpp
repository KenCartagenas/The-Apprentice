#include <raylib.h>
#include "includes/Game.h"

const int screenWidth = 800;
const int screenHeight = 600;
const int fps = 60;
const Color bgcolor = {0, 0, 0, 255};

int main() {
    InitWindow(screenWidth, screenHeight, "The Apprentice");
    SetTargetFPS(fps);

    Game game;
    
    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(bgcolor);
        game.update();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}