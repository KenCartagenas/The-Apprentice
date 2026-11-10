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
    void drawComponents();
};