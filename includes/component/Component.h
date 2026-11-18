#pragma once
#include <raylib.h>
#include <string>
#include <vector>

class Component {
public:
    virtual void draw(int frameNumber) = 0;
    virtual void setPosition(Vector2 pos) = 0;
    virtual void setDimension(Vector2 dimension) = 0;
    virtual void setTexture(std::vector<Texture2D>* newTextures) = 0;
    virtual Vector2 getPositionXY() = 0;
    virtual Vector2 getDimension() = 0;
    virtual std::string getID() = 0;
    virtual ~Component() = default;
};