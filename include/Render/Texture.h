#ifndef TEXTURE_H
#define TEXTURE_H
#include <SDL2/SDL.h>

namespace Core {
    class Texture {
    public:
        Texture() {}
        Texture(const char* name, SDL_Rect rect, SDL_Texture* texture);
        const char* name;
        SDL_Rect rect;
        SDL_Texture *data;
    };
}

#endif