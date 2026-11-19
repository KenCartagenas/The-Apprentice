#include "../../includes/screen/GameMap.h"
#include "../../includes/component/Map.h"

void GameMap::initScreen() {
    GameMapRenderer->addComponent(std::make_unique<Map>("map" ,textureHandler->getTexture("mapTileset"), Vector2({6,23})));
}