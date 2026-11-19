#include "../../includes/screen/GameMap.h"
#include "../../includes/map/Map.h"

void GameMap::initScreen() {
    Map map("map" ,textureHandler->getTexture("mapTileset"), Vector2({6,23}));
    Map *mapptr = &map;
    GameMapRenderer->setMap(mapptr);
}