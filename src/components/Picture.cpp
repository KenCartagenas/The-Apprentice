#include "../../includes/component/Picture.h"
#include <raylib.h>

void Picture::draw(int frameNumber) {
    Rectangle source = {
        0, 0,
        (float)textures->at(frameNumber%textures->size()).width,
        (float)textures->at(frameNumber%textures->size()).height
    };
    Rectangle dest = {
        x, y,
        width,
        height
    };
    DrawTexturePro(textures->at((frameNumber/25)%textures->size()), source, dest, Vector2({0,0}), 0.0f, WHITE);
}

Vector2 Picture::getPositionXY() {
    return Vector2({x,y});
}

Vector2 Picture::getDimension() {
    return Vector2({width,height});
}

std::string Picture::getID() {
    return id;
}

void Picture::setPosition(Vector2 pos) {
    x = pos.x;
    y = pos.y;
}
void Picture::setDimension(Vector2 dimension) {
    width = dimension.x;
    height = dimension.y;
}

void Picture::setTexture(std::vector<Texture2D>* newTextures) {
    textures = newTextures;
}
