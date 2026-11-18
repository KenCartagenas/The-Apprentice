#pragma once
#include <vector>
#include <memory>
#include <raylib.h>
#include "../component/Component.h"

class Renderer {
public:
    std::vector<std::unique_ptr<Component>> components;
    void addComponent(std::unique_ptr<Component> component);
    std::string getComponentClicked(Vector2 mouseClickPosition);
    void drawComponents(int frameNumber);
    void setPosition(std::string id, Vector2 position);
    void setDimension(std::string id, Vector2 dimension);
    void setTexture(std::string id, std::vector<Texture2D>* newTextures);
    Vector2 getPosition(std::string id);
    Vector2 getDimension(std::string id);
};