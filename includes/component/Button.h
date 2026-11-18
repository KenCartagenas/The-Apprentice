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
    float roundness;
    int fontSize;
    int offsetTextX;
    int offsetTextY;
    Color color;
    Color fontColor;
    Rectangle rec;

public:
    Button(std::string id, const char *text, float posX, float posY, float width, float height, float roundness, Color color, Color fontColor) 
    : text(text), id(id), x(posX), y(posY), width(width), height(height), color(color), roundness(roundness), rec{x,y,width,height}, fontColor(fontColor) {
        int currentWidth = MeasureText(text, 10);
        int targetWidth = width*0.8;
        float scaleFactor = (float)targetWidth / (float)currentWidth;
        fontSize = (int)(10*scaleFactor);
        offsetTextY = (height-(float)fontSize)/2;
        offsetTextX = (width-MeasureText(text, fontSize))/2;
    }
    void setColor(Color newColor);
    void draw(int frameNumber) override;
    void setPosition(Vector2 pos) override;
    void setDimension(Vector2 dimension) override;
    void setTexture(std::vector<Texture2D>* newTextures) override;
    Vector2 getPositionXY() override;
    Vector2 getDimension() override;
    std::string getID() override;
};
