#pragma once
#include <raylib.h>
#include "Component.h"

class Button : public Component{
private:
    const char *text;
    float x;
    float y;
    float width;
    float height;
    int fontSize;
    int offsetTextX;
    int offsetTextY;
    Color color;
    Rectangle rec;

public:
    Button(const char *text, float posX, float posY, float width, float height, Color color) 
    : text(text), x(posX), y(posY), width(width), height(height), color(color), rec{x,y,width,height} {
        int currentWidth = MeasureText(text, 10);
        int targetWidth = width*0.8;
        float scaleFactor = (float)targetWidth / (float)currentWidth;
        fontSize = (int)(10*scaleFactor);
        offsetTextY = (height-(float)fontSize)/2;
        offsetTextX = (width-MeasureText(text, fontSize))/2;
    }
    void draw() override;
};
