#include "../../includes/renderer/Renderer.h"
#include <memory>

void Renderer::addComponent(std::unique_ptr<Component> component) { 
    components.push_back(std::move(component)); 
}

void Renderer::drawComponents() { 
    for (const auto& component : components) {
        component->draw();
    }
}