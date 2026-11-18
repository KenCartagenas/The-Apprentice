#pragma once
#include <vector>
#include <string>
#include <raylib.h>

class TextureAsset {
private:
    std::string id;
    int frames;
    std::vector<Texture2D> textures;

public:
    TextureAsset(std::string id, int frames, std::string directory) : id(id), frames(frames) {
        for (int i = 1; i < frames+1; i++) {
            std::string path = std::string(directory) + std::to_string(i) + ".png";
            const char *file = path.c_str();
            textures.push_back(LoadTexture(file));
        }
    }
    std::string getID();
    std::vector<Texture2D> *getTexture();
};