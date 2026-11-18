#include "../../includes/component/Map.h"
#include "../../includes/component/MapElements.h"
#include <random>
#include <iostream>

void Map::generateMap() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 100);
    std::cout << map.size() << " " << map[0].size() << '\n';
    std::cout << GetScreenHeight() << " " << GetScreenWidth() << '\n';
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[0].size(); j++) {
            int num = (dist(gen)%8)+1;
            std::string newStr = "grass" + std::to_string(num);
            map[i][j] = newStr;
        }
    }
    Vector2 soilPath = {0, 0};
}

void Map::draw(int frameNumber) {
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[0].size(); j++) {
            std::string element = map[i][j];
            Vector2 coordinate = MapElements::tileCoordinates.at(element);
            Rectangle source = {
                coordinate.x*16, coordinate.y*16,
                16,
                16
            };
            Rectangle dest = {
                j*32.0f, i*32.0f,
                32,
                32
            };
            DrawTexturePro(textures->at((frameNumber/25)%textures->size()), source, dest, Vector2({0,0}), 0.0f, WHITE);
        }
    }
}

Vector2 Map::getPositionXY() {
    return Vector2({x,y});
}

Vector2 Map::getDimension() {
    return Vector2({width,height});
}

std::string Map::getID() {
    return id;
}

void Map::setPosition(Vector2 pos) {
    x = pos.x;
    y = pos.y;
}
void Map::setDimension(Vector2 dimension) {
    width = dimension.x;
    height = dimension.y;
}

void Map::setTexture(std::vector<Texture2D>* newTextures) {
    textures = newTextures;
}

