#include "../../includes/component/Button.h"
#include <raylib.h>

void Button::draw() {
    DrawRectangleRounded(rec,0.8,16,color);
    DrawText(text, x+offsetTextX, y+offsetTextY, fontSize, Color({145,234,235,255}));
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
