#include "../../includes/renderer/Renderer.h"
#include "../../includes/map/Map.h"
#include <string>
#include <memory>

void Renderer::addComponent(std::unique_ptr<Component> component) {
    components.push_back(std::move(component)); 
}

void Renderer::setMap(Map *mapPtr) {
    map = mapPtr;
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

void Renderer::drawComponents(int frameNumber) { 
    for (const auto& component : components) {
        component->draw(frameNumber);
    }
    map->draw(frameNumber);
}

void Renderer::setPosition(std::string id, Vector2 position) {
    for(const auto& component : components) {
        if (component->getID() == id) {
            component->setPosition(position);
            break;
        }
    }
}

void Renderer::setDimension(std::string id, Vector2 dimension) {
    for(const auto& component : components) {
        if (component->getID() == id) {
            component->setDimension(dimension);
            break;
        }
    }
}

void Renderer::setTexture(std::string id, std::vector<Texture2D>* newTextures) {
    for(const auto& component : components) {
        if (component->getID() == id) {
            component->setTexture(newTextures);
            break;
        }
    }
}

Vector2 Renderer::getPosition(std::string id) {
    for(const auto& component : components) {
        if (component->getID() == id) {
            return component->getPositionXY();
        }
    }
    return Vector2({-1,-1});
}

Vector2 Renderer::getDimension(std::string id) {
    for(const auto& component : components) {
        if (component->getID() == id) {
            return component->getDimension();
        }
    }
    return Vector2({-1,-1});
}
