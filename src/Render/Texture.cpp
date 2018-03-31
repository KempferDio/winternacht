#include <Render/Texture.h>

using namespace Core;

Texture::Texture(const char* name, SDL_Rect rect, SDL_Texture* texture) {
    this->name = name;
    this->rect = rect;
    this->data = texture;
}
