#pragma once
#include "Component.h"
#include <vector>
#include <string>
#include <iostream>
#include <cmath>

class Map : public Component{
private:
    std::string id;
    float x = 0;
    float y = 0;
    float height;
    float width;
    std::vector<Texture2D>* textures;
    std::vector<std::vector<std::string>> map;

public:
    Map(std::vector<Texture2D>* textures) : textures(textures) {
        map.assign(
            (int)std::ceil(GetScreenHeight()/32.0f),
            std::vector<std::string>((int)std::ceil(GetScreenWidth()/32.0f), "")
        );
        generateMap();
    }
    void generateMap();
    void draw(int frameNumber) override;
    void setPosition(Vector2 pos) override;
    void setDimension(Vector2 dimension) override;
    void setTexture(std::vector<Texture2D>* newTextures) override;
    Vector2 getPositionXY() override;
    Vector2 getDimension() override;
    std::string getID() override;
};