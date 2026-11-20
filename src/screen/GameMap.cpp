#include "../../includes/screen/GameMap.h"
#include "../../includes/map/Map.h"

void GameMap::initScreen(Map *mapptr) {
    GameMapRenderer->setMap(mapptr);
}