#pragma once
#include "Component.h"
#include <vector>
#include <raylib.h>
#include <string>

class Picture : public Component {
private:
    std::string id;
    float x;
    float y;
    float width;
    float height;
    std::vector<Texture2D>* textures;

public:
    Picture(std::string id, std::vector<Texture2D>* textures, float posX, float posY, float width, float height) : 
    textures(textures), id(id), x(posX), y(posY), width(width), height(height) {}
    void draw(int frameNumber) override;
    void setPosition(Vector2 pos) override;
    void setDimension(Vector2 dimension) override;
    void setTexture(std::vector<Texture2D>* newTextures) override;
    Vector2 getPositionXY() override;
    Vector2 getDimension() override;
    std::string getID() override;
};