#pragma once
#include <raylib.h>
#include <string>
#include "Component.h"

class Button : public Component{
private:
    std::string id;
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
    Button(const char *text, std::string id, float posX, float posY, float width, float height, Color color) 
    : text(text), id(id), x(posX), y(posY), width(width), height(height), color(color), rec{x,y,width,height} {
        int currentWidth = MeasureText(text, 10);
        int targetWidth = width*0.8;
        float scaleFactor = (float)targetWidth / (float)currentWidth;
        fontSize = (int)(10*scaleFactor);
        offsetTextY = (height-(float)fontSize)/2;
        offsetTextX = (width-MeasureText(text, fontSize))/2;
    }
    void draw() override;
    Vector2 getPositionXY() override;
    Vector2 getDimension() override;
    std::string getID() override;
};
