#include "../../includes/utilities/TextureHandler.h"
#include <raylib.h>
#include <string>

std::vector<Texture2D> *TextureHandler::getTexture(std::string id) {
    for(auto& texture : textures) {
        if(texture->getID() == id) {
            return texture->getTexture();
        }
    }
    return nullptr;
}

void TextureHandler::addTexture(std::unique_ptr<TextureAsset> texture) {
    textures.push_back(std::move(texture));
}
