#include <Texture.h>

using namespace Core;

Texture::Texture() {
    this->texture = NULL;
    this->textureWidth = 0;
    this->textureHeight = 0;
}

Texture::~Texture() {
    free();
}

void Texture::free() {
    if(this->texture != NULL) {
        SDL_DestroyTexture(this->texture);
        this->texture = NULL;
        this->textureWidth = 0;
        this->textureHeight = 0;
    }
}


int Texture::getWidth() {
    return this->textureWidth;
}

int Texture::getHeight() {
    return this->textureHeight;
}