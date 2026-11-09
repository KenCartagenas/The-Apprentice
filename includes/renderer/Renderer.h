#pragma once
#include <vector>
#include <memory>
#include "../component/Component.h"

class Renderer {
public:
    std::vector<std::unique_ptr<Component>> components;
    void addComponent(std::unique_ptr<Component> component);
    void drawComponents();
};