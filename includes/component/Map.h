#pragma once
#include "Component.h"
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <utility>

class Map : public Component {
private:
    std::string id;
    float x = 0;
    float y = 0;
    float height;
    float width;
    std::vector<Texture2D>* textures;
    std::vector<std::vector<std::string>> baseMap;
    std::vector<Vector2> topLeftSoils;
    std::vector<Vector2> topRightSoils;
    std::vector<Vector2> bottomLeftSoils;
    std::vector<Vector2> bottomRightSoils;
    std::vector<Vector2> bushes;
    std::vector<Vector2> sparkles;
    std::vector<std::pair<int, Vector2>> stones;
    std::vector<std::pair<int, Vector2>> flowers;
    Vector2 blockPathStart;
    Vector2 blockPathEnd;
    void generateMap();
    void generateBaseMap();

public:
    Map(std::string id, std::vector<Texture2D>* textures, Vector2 blockPathStart) : id(id), textures(textures), blockPathStart(blockPathStart) {
        baseMap.assign(
            (int)std::ceil(GetScreenHeight()/32.0f),
            std::vector<std::string>((int)std::ceil(GetScreenWidth()/32.0f), "")
        );
        generateMap();
    }
    void draw(int frameNumber) override;
    void setPosition(Vector2 pos) override;
    void setDimension(Vector2 dimension) override;
    void setTexture(std::vector<Texture2D>* newTextures) override;
    Vector2 getPositionXY() override;
    Vector2 getDimension() override;
    std::string getID() override;
};