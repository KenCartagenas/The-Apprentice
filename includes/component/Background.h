#pragma once
#include <raylib.h>
#include <string>
#include "Component.h"

class Background : public Component {
private:
    std::string id;
    float x = 0;
    float y = 0;
    float width;
    float height;
    Texture2D backgroundImage;

public:
    Background(const char* file, std::string id) : 
    id(id), width((float)GetScreenWidth()), height((float)GetScreenHeight()) {
        backgroundImage = LoadTexture(file);
        if(backgroundImage.id == 0) {
            TraceLog(LOG_ERROR, "Failed to load JPEG");
        }
    }
    void draw() override;
    Vector2 getPositionXY() override;
    Vector2 getDimension() override;
    std::string getID() override;
    ~Background() {
        UnloadTexture(backgroundImage);
    }
};