#include "../../includes/player/Player.h"
#include <raylib.h>
#include <iostream>

void Player::drawPlayer(int frameNumber) {
    std::vector<Texture2D>* frames = textures[state];
    if(frames == nullptr) {
        return;
    }
    Rectangle source = {
        0, 0,
        lookingRight ? 16.0f : -16.0f, 16.0f
    };
    Rectangle dest = {
        position.x*32.0f, position.y*32.0f,
        64, 64
    };
    int fps = (state == "idle") ? (frameNumber/10)%frames->size() : (frameNumber/15)%frames->size();
    DrawTexturePro(frames->at(fps), source, dest, Vector2({0,0}), 0.0f, WHITE);
}

void Player::update(int frameNumber) {
    if(IsKeyPressed(KEY_SPACE)) {
        isAttacking = true;
    }
    
    if (!isAttacking) {
        if (IsKeyDown(KEY_W)) {
            position.y -= speed * GetFrameTime();
            state = "running";
        }
        if (IsKeyDown(KEY_S)) {
            position.y += speed * GetFrameTime();
            state = "running";
        }
        if (IsKeyDown(KEY_A)) {
            position.x -= speed * GetFrameTime();
            lookingRight = false;
            state = "running";
        } 
        if (IsKeyDown(KEY_D)) {
            position.x += speed * GetFrameTime();
            lookingRight = true;
            state = "running";
        }
    }
    drawPlayer(frameNumber);
    state = "idle";
}

void Player::setPosition(Vector2 pos)
{
    position = pos;
}

Vector2 Player::getPosition() {
    return position;
}