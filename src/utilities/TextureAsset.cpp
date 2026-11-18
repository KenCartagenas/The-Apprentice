#include "../../includes/utilities/TextureAsset.h"

std::string TextureAsset::getID() {
    return id;
}

std::vector<Texture2D> *TextureAsset::getTexture() {
    return &textures;
}
