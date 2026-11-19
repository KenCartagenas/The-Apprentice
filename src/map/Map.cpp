#include "../../includes/map/Map.h"
#include "../../includes/map/MapElements.h"
#include <random>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <cmath>

void Map::generateMap() {
    generateBaseMap();
}

void Map::generateBaseMap() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 100);
    for (int i = 0; i < baseMap.size(); i++) {
        for (int j = 0; j < baseMap[0].size(); j++) {
            int num = (dist(gen)%8)+1;
            std::string newStr = "grass" + std::to_string(num);
            baseMap[i][j] = newStr;
        }
    }
    std::vector<int> pathChoicesX = {0, (int)baseMap[0].size()};
    std::vector<int> pathChoicesY = {0, (int)baseMap.size()};
    if (blockPathStart.x == 0) {
        if(dist(gen)%2==0) {
            blockPathEnd.x = pathChoicesX[1]-1;
            blockPathEnd.y = (dist(gen)%(pathChoicesY[1]-4))+2;
        } else {
            blockPathEnd.x = (dist(gen)%(pathChoicesX[1]-4))+2;
            blockPathEnd.y = (dist(gen)%2) ? pathChoicesY[1]-1 : pathChoicesY[0];
        }
    } else if(blockPathStart.y == 0) {
        if(dist(gen)%2==0) {
            blockPathEnd.y = pathChoicesY[1]-1;
            blockPathEnd.x = (dist(gen)%(pathChoicesX[1]-4))+2;
        } else {
            blockPathEnd.y = (dist(gen)%(pathChoicesY[1]-4))+2;
            blockPathEnd.x = pathChoicesX[1]-1;
        }
    } else if(blockPathStart.y == pathChoicesY[1]-1) {
        if(dist(gen)%2==0) {
            blockPathEnd.y = pathChoicesY[0];
            blockPathEnd.x = (dist(gen)%(pathChoicesX[1]-4))+2;
        } else {
            blockPathEnd.y = (dist(gen)%(pathChoicesY[1]-4))+2;
            blockPathEnd.x = pathChoicesX[1]-1;
        }
    }
    if (blockPathStart.x == 0) {
        if(blockPathEnd.x == pathChoicesX[1]-1) {
            int mid = pathChoicesX[1]/2;
            int gap = blockPathEnd.y-blockPathStart.y;
            int yOffset = 0;
            for (int i = 0; i <= blockPathEnd.x; i++) {
                if (i > mid-std::abs(gap/2) && i < (mid+std::abs(gap/2))) {
                    yOffset += (gap>0) ? 1 : -1;
                    if(gap > 0) {
                        float x = i;
                        float y = blockPathStart.y+yOffset-1;
                        topRightSoils.push_back(Vector2({x,y}));
                        x -= 1;
                        y += 3;
                        bottomLeftSoils.push_back(Vector2({x,y}));
                    } else {
                        float x = i;
                        float y = blockPathStart.y+yOffset+3;
                        bottomRightSoils.push_back(Vector2({x, y}));
                        x -= 1;
                        y -= 3;
                        topLeftSoils.push_back(Vector2({x,y}));
                    }
                }
                for (int j = 0; j < 3; j++) {
                    baseMap[blockPathStart.y+j+yOffset][i] = "soil";
                }
            }
            blockPathEnd.y = blockPathStart.y+yOffset;
        } else if(blockPathEnd.y == 0) {
            for(int i = 0; i < 3; i++) {
                for (int j = 0; j <= blockPathEnd.x+i; j++) {
                    baseMap[blockPathStart.y+i][j] = "soil";
                }
            }
            for (int i = 0; i < 3; i++) {
                for (int j = 1; j <= blockPathStart.y-blockPathEnd.y+i; j++) {
                    baseMap[blockPathStart.y+i-j][blockPathEnd.x+i] = "soil";
                }
            }
        } else if(blockPathEnd.y == pathChoicesY[1]-1) {
            for(int i = 2; i >= 0; i--) {
                for (int j = 0; j <= blockPathEnd.x+i; j++) {
                    baseMap[blockPathStart.y+2-i][j] = "soil";
                }
            }
            for (int i = 0; i < 3; i++) {
                for (int j = 1; j <= blockPathEnd.y-blockPathStart.y-i; j++) {
                    baseMap[blockPathStart.y+i+j][blockPathEnd.x+2-i] = "soil";
                }
            }
        }
    } else if(blockPathStart.y == 0) {
        if(blockPathEnd.y == pathChoicesY[1]-1) {
            int mid = pathChoicesY[1]/2;
            int gap = blockPathEnd.x-blockPathStart.x;
            int xOffset = 0;
            for (int i = 0; i <= blockPathEnd.y; i++) {
                if (i > mid-std::abs(gap/2) && i < (mid+std::abs(gap/2))) {
                    xOffset += (gap>0) ? 1 : -1;
                    if(gap > 0) {
                        float y = i;
                        float x = blockPathStart.x+xOffset-1;
                        bottomLeftSoils.push_back(Vector2({x,y}));
                        y -= 1;
                        x += 3;
                        topRightSoils.push_back(Vector2({x,y}));
                    } else {
                        float y = i;
                        float x = blockPathStart.x+xOffset+3;
                        bottomRightSoils.push_back(Vector2({x, y}));
                        y -= 1;
                        x -= 3;
                        topLeftSoils.push_back(Vector2({x,y}));
                    }
                }
                for (int j = 0; j < 3; j++) {
                    baseMap[i][blockPathStart.x+j+xOffset] = "soil";
                }
            }
            blockPathEnd.x = blockPathStart.x+xOffset;
        } else if(blockPathEnd.x == pathChoicesX[1]-1) {
            for(int i = 2; i >= 0; i--) {
                for (int j = 0; j <= blockPathEnd.y+i; j++) {
                    baseMap[j][blockPathStart.x+2-i] = "soil";
                }
            }
            for (int i = 0; i < 3; i++) {
                for (int j = 1; j <= blockPathEnd.x-blockPathStart.x-i; j++) {
                    baseMap[blockPathEnd.y+2-i][blockPathStart.x+i+j] = "soil";
                }
            }
        }
    } else if(blockPathStart.y == pathChoicesY[1]-1) {
        if(blockPathEnd.y == 0) {
            int mid = pathChoicesY[1]/2;
            int gap = blockPathEnd.x-blockPathStart.x;
            int xOffset = 0;
            for (int i = blockPathStart.y; i >= 0; i--) {
                if (i > mid-std::abs(gap/2) && i < (mid+std::abs(gap/2))) {
                    xOffset += (gap>0) ? 1 : -1;
                    if(gap > 0) {
                        float y = i;
                        float x = blockPathStart.x+xOffset-1;
                        topLeftSoils.push_back(Vector2({x,y}));
                        y += 1;
                        x += 3;
                        bottomRightSoils.push_back(Vector2({x,y}));
                    } else {
                        float y = i+1;
                        float x = blockPathStart.x+xOffset;
                        bottomLeftSoils.push_back(Vector2({x, y}));
                        y -= 1;
                        x += 3;
                        topRightSoils.push_back(Vector2({x,y}));
                    }
                }
                for (int j = 0; j < 3; j++) {
                    baseMap[i][blockPathStart.x+j+xOffset] = "soil";
                }
            }
            blockPathEnd.x = blockPathStart.x+xOffset;
        } else if(blockPathEnd.x == pathChoicesX[1]-1) {
            for(int i = 2; i >= 0; i--) {
                for (int j = blockPathStart.y; j >= blockPathEnd.y+i; j--) {
                    baseMap[j][blockPathStart.x+i] = "soil";
                }
            }
            for (int i = 2; i >= 0; i--) {
                for (int j = 2; j <= blockPathEnd.x-blockPathStart.x+i; j++) {
                    baseMap[blockPathEnd.y+2-i][blockPathStart.x+j-i] = "soil";
                }
            }
        }
    }

    for (size_t i = 0; i < (dist(gen)%6)+5; i++) {
        float x = -1;
        float y = -1;
        while (x == -1 || y == -1) {
            x = (float)(dist(gen)%baseMap[0].size());
            y = (float)(dist(gen)%baseMap.size());
            if(baseMap[y][x] != "soil")
                bushes.push_back(Vector2({x, y}));
        }   
    }
    for (size_t i = 0; i < (dist(gen)%6)+5; i++) {
        float x = -1;
        float y = -1;
        while (x == -1 || y == -1) {
            x = (float)(dist(gen)%baseMap[0].size());
            y = (float)(dist(gen)%baseMap.size());
            if(baseMap[y][x] != "soil") {
                int number = (dist(gen)%4)+1;
                std::pair<int, Vector2> stone = {number, Vector2({x, y})};
                stones.push_back(stone);
            }
        }   
    }
    for (size_t i = 0; i < (dist(gen)%6)+5; i++) {
        float x = -1;
        float y = -1;
        while (x == -1 || y == -1) {
            x = (float)(dist(gen)%baseMap[0].size());
            y = (float)(dist(gen)%baseMap.size());
            if(baseMap[y][x] != "soil") {
                int number = (dist(gen)%12)+1;
                std::pair<int, Vector2> flower = {number, Vector2({x, y})};
                flowers.push_back(flower);
            }
        }   
    }

    if (blockPathEnd.y == 0 || blockPathEnd.y == pathChoicesY[1]-1) {
        for (size_t i = 0; i < 3; i++) {
            Vector2 sparkle = {blockPathEnd.x+i, blockPathEnd.y};
            sparkles.push_back(sparkle);
        }
    } else if(blockPathEnd.x == pathChoicesX[1]-1) {
        for (size_t i = 0; i < 3; i++) {
            Vector2 sparkle = {blockPathEnd.x, blockPathEnd.y+i};
            sparkles.push_back(sparkle);
        }
    }
}

void Map::draw(int frameNumber) {
    for (int i = 0; i < baseMap.size(); i++) {
        for (int j = 0; j < baseMap[0].size(); j++) {
            std::string element = baseMap[i][j];
            Vector2 coordinate = MapElements::tileCoordinates.at(element);
            Rectangle source = {
                coordinate.x*16, coordinate.y*16,
                16,
                16
            };
            Rectangle dest = {
                j*32.0f, i*32.0f,
                32,
                32
            };
            DrawTexturePro(textures->at((frameNumber/25)%textures->size()), source, dest, Vector2({0,0}), 0.0f, WHITE);
        }
    }
    for (int i = 0; i < topLeftSoils.size(); i++) {
        std::string element = "topLeftSoil";
        Vector2 coordinate = MapElements::tileCoordinates.at(element);
        Rectangle source = {
            coordinate.x*16, coordinate.y*16,
            16,
            16
        };
        Rectangle dest = {
            topLeftSoils[i].x*32.0f, topLeftSoils[i].y*32.0f,
            32,
            32
        };
        DrawTexturePro(textures->at((frameNumber/25)%textures->size()), source, dest, Vector2({0,0}), 0.0f, WHITE);
    }
    for (int i = 0; i < topRightSoils.size(); i++) {
        std::string element = "topRightSoil";
        Vector2 coordinate = MapElements::tileCoordinates.at(element);
        Rectangle source = {
            coordinate.x*16, coordinate.y*16,
            16,
            16
        };
        Rectangle dest = {
            topRightSoils[i].x*32.0f, topRightSoils[i].y*32.0f,
            32,
            32
        };
        DrawTexturePro(textures->at((frameNumber/25)%textures->size()), source, dest, Vector2({0,0}), 0.0f, WHITE);
    }
    for (int i = 0; i < bottomLeftSoils.size(); i++) {
        std::string element = "bottomLeftSoil";
        Vector2 coordinate = MapElements::tileCoordinates.at(element);
        Rectangle source = {
            coordinate.x*16, coordinate.y*16,
            16,
            16
        };
        Rectangle dest = {
            bottomLeftSoils[i].x*32.0f, bottomLeftSoils[i].y*32.0f,
            32,
            32
        };
        DrawTexturePro(textures->at((frameNumber/25)%textures->size()), source, dest, Vector2({0,0}), 0.0f, WHITE);
    }
    for (int i = 0; i < bottomRightSoils.size(); i++) {
        std::string element = "bottomRightSoil";
        Vector2 coordinate = MapElements::tileCoordinates.at(element);
        Rectangle source = {
            coordinate.x*16, coordinate.y*16,
            16,
            16
        };
        Rectangle dest = {
            bottomRightSoils[i].x*32.0f, bottomRightSoils[i].y*32.0f,
            32,
            32
        };
        DrawTexturePro(textures->at((frameNumber/25)%textures->size()), source, dest, Vector2({0,0}), 0.0f, WHITE);
    }
    
    for (int i = 0; i < bushes.size(); i++) {
        std::string element = "bushFrame" + std::to_string((frameNumber/15)%4+1);
        Vector2 coordinate = MapElements::tileCoordinates.at(element);
        Rectangle source = {
            coordinate.x*16, coordinate.y*16,
            16,
            16
        };
        Rectangle dest = {
            bushes[i].x*32.0f, bushes[i].y*32.0f,
            32,
            32
        };
        DrawTexturePro(textures->at((frameNumber/25)%textures->size()), source, dest, Vector2({0,0}), 0.0f, WHITE);
    }

    for (int i = 0; i < stones.size(); i++) {
        std::string element = "stone" + std::to_string(stones[i].first);
        Vector2 coordinate = MapElements::tileCoordinates.at(element);
        Rectangle source = {
            coordinate.x*16, coordinate.y*16,
            16,
            16
        };
        Rectangle dest = {
            stones[i].second.x*32.0f, stones[i].second.y*32.0f,
            32,
            32
        };
        DrawTexturePro(textures->at((frameNumber/25)%textures->size()), source, dest, Vector2({0,0}), 0.0f, WHITE);
    }
    
    for (int i = 0; i < flowers.size(); i++) {
        std::string element = "flower" + std::to_string(flowers[i].first);
        Vector2 coordinate = MapElements::tileCoordinates.at(element);
        Rectangle source = {
            coordinate.x*16, coordinate.y*16,
            16,
            16
        };
        Rectangle dest = {
            flowers[i].second.x*32.0f, flowers[i].second.y*32.0f,
            32,
            32
        };
        DrawTexturePro(textures->at((frameNumber/25)%textures->size()), source, dest, Vector2({0,0}), 0.0f, WHITE);
    }

    for (int i = 0; i < sparkles.size(); i++) {
        std::string element = "sparkle" + std::to_string((frameNumber/15)%4+1);
        Vector2 coordinate = MapElements::tileCoordinates.at(element);
        Rectangle source = {
            coordinate.x*16, coordinate.y*16,
            16,
            16
        };
        Rectangle dest = {
            sparkles[i].x*32.0f, sparkles[i].y*32.0f,
            32,
            32
        };
        DrawTexturePro(textures->at((frameNumber/25)%textures->size()), source, dest, Vector2({0,0}), 0.0f, WHITE);
    }
}

Vector2 Map::getBlockPathEnd() {
    return blockPathEnd;
}


std::string Map::getID() {
    return id;
}

void Map::setBlockPathStart(Vector2 pos) {
    topLeftSoils.clear();
    topRightSoils.clear();
    bottomLeftSoils.clear();
    bottomRightSoils.clear();
    bushes.clear();
    stones.clear();
    flowers.clear();
    sparkles.clear();
    if(pos.y == 0) {
        blockPathStart.y = baseMap.size()-1;
        blockPathStart.x = pos.x;
    } else if(pos.y == baseMap.size()-1) {
        blockPathStart.y = 0;
        blockPathStart.x = pos.x;
    } else if(pos.x = baseMap[0].size()-1) {
        blockPathStart.x = 0;
        blockPathStart.y = pos.y;
    }
    generateMap();
}
