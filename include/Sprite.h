#ifndef SPRITE_H
#define SPRITE_H

#include <Log.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <vector>

namespace Core {
    class Sprite {
        public:
            Sprite() {}
            Sprite(int clipRowCount, int clipColumnCount, int clipSize, SDL_Texture* texture);
            ~Sprite();

            int clipRowCount;
            int clipColumnCount;
            int clipSize;
            std::vector<SDL_Rect> clips;
            SDL_Texture *texture;

    };
}

#endif