#include "../../includes/screen/GameMap.h"
#include "../../includes/component/Map.h"

void GameMap::initScreen() {
    GameMapRenderer->addComponent(std::make_unique<Map>(textureHandler->getTexture("mapTileset")));
}