#pragma once
#include <raylib.h>
#include <vector>
#include <unordered_map>
#include <string>

class Player {
private:
    Vector2 position;
    Vector2 dimension;
    std::string state;
    bool lookingRight = true;
    bool isAttacking = false;
    float speed = 5;
    std::unordered_map<std::string, std::vector<Texture2D>*> textures;
    void drawPlayer(int frameNumber);

public:
    Player() = default;
    Player(Vector2 position, Vector2 dimension, std::unordered_map<std::string, std::vector<Texture2D>*> textures) : position(position), dimension(dimension), textures(textures) {}
    void update(int frameNumber);
    void setPosition(Vector2 pos);
    Vector2 getPosition();
};