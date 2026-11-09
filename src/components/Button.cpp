#include "../../includes/component/Button.h"
#include <raylib.h>

void Button::draw() {
    DrawRectangleRounded(rec,0.8,16,color);
    DrawText(text, x+offsetTextX, y+offsetTextY, fontSize, Color({145,234,235,255}));
}