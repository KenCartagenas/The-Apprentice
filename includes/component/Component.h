#pragma once
#include <raylib.h>
#include <string>

class Component {
public:
    virtual void draw() = 0;
    virtual Vector2 getPositionXY() = 0;
    virtual Vector2 getDimension() = 0;
    virtual std::string getID() = 0;
    virtual ~Component() = default;
};