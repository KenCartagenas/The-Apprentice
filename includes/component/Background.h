#pragma once
#include <raylib.h>
#include <string>
#include <vector>
#include "Component.h"

class Background : public Component {
private:
    std::string id;
    float x = 0;
    float y = 0;
    float width;
    float height;
    std::vector<Texture2D>* textures;

public:
    Background(std::string id, std::vector<Texture2D>* textures) : 
    id(id), width((float)GetScreenWidth()), height((float)GetScreenHeight()), textures(textures) {}
    void draw(int frameNumber) override;
    void setPosition(Vector2 pos) override;
    void setDimension(Vector2 dimension) override;
    void setTexture(std::vector<Texture2D>* newTextures) override;
    Vector2 getPositionXY() override;
    Vector2 getDimension() override;
    std::string getID() override;
};