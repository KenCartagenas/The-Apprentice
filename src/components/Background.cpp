#include "../../includes/component/Background.h"
#include <raylib.h>

void Background::draw() {
    DrawTexture(backgroundImage, x, y, WHITE);
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
