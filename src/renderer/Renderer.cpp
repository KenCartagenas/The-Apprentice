#include "../../includes/renderer/Renderer.h"
#include <string>
#include <memory>

void Renderer::addComponent(std::unique_ptr<Component> component) {
    components.push_back(std::move(component)); 
}

std::string Renderer::getComponentClicked(Vector2 mouseClickPosition) {
    for (auto it = components.rbegin(); it != components.rend(); it++) {
        if (mouseClickPosition.x >= (*it)->getPositionXY().x && 
            mouseClickPosition.x <= (*it)->getPositionXY().x+(*it)->getDimension().x && 
            mouseClickPosition.y >= (*it)->getPositionXY().y && 
            mouseClickPosition.y <= (*it)->getPositionXY().y+(*it)->getDimension().y) {
            return (*it)->getID();
        }
    }
    return "none";
}

void Renderer::drawComponents() { 
    for (const auto& component : components) {
        component->draw();
    }
}