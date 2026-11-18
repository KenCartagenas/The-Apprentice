#pragma once
#include "TextureAsset.h"
#include <raylib.h>
#include <string>
#include <memory>

class TextureHandler {
private:
    std::vector<std::unique_ptr<TextureAsset>> textures;

public:
    TextureHandler(){}
    std::vector<Texture2D>* getTexture(std::string id);
    void addTexture(std::unique_ptr<TextureAsset> texture);
};