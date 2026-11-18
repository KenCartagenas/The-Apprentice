#include "../../includes/component/Button.h"
#include <raylib.h>

void Button::setColor(Color newColor) {
    color = newColor;
}

void Button::draw(int frameNumber)
{
    DrawRectangleRounded(rec,roundness,16,color);
    DrawText(text, x+offsetTextX, y+offsetTextY, fontSize, fontColor);
}

Vector2 Button::getPositionXY() {
    return Vector2({x,y});
}

Vector2 Button::getDimension() {
    return Vector2({width,height});
}

std::string Button::getID() {
    return id;
}

void Button::setPosition(Vector2 pos) {
    x = pos.x;
    y = pos.y;
}
void Button::setDimension(Vector2 dimension) {
    width = dimension.x;
    height = dimension.y;
}

void Button::setTexture(std::vector<Texture2D>* newTextures) {}
