#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <Log.h>
#include <Texture.h>

namespace Core {
    class Texture {
        public:
            Texture();
            ~Texture();
            int getWidth();
            int getHeight();
            SDL_Texture *texture;
            int textureWidth;
            int textureHeight;
            void free();
    };
}

#endif