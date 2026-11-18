#include "../../includes/component/Background.h"
#include <raylib.h>

void Background::draw(int frameNumber) {
    Rectangle source = {
        0, 0,
        (float)textures->at(frameNumber%textures->size()).width,
        (float)textures->at(frameNumber%textures->size()).height
    };
    Rectangle dest = {
        0, 0,
        width,
        height
    };
    DrawTexturePro(textures->at((frameNumber/25)%textures->size()), source, dest, Vector2({0,0}), 0.0f, WHITE);
}

Vector2 Background::getPositionXY() {
    return Vector2({x,y});
}

Vector2 Background::getDimension() {
    return Vector2({width,height});
}

std::string Background::getID() {
    return id;
}

void Background::setPosition(Vector2 pos) {
    x = pos.x;
    y = pos.y;
}
void Background::setDimension(Vector2 dimension) {
    width = dimension.x;
    height = dimension.y;
}

void Background::setTexture(std::vector<Texture2D>* newTextures) {
    textures = newTextures;
}
