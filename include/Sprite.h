#ifndef SPRITE_H
#define SPRITE_H

#include <Log.h>
#include <Texture.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <vector>

namespace Core {
    class Sprite {
        public:
            Sprite() {}
            Sprite(int clipRowCount, int clipColumnCount, int clipSize, Texture* texture);
            ~Sprite();

            int clipRowCount;
            int clipColumnCount;
            int clipSize;
            std::vector<SDL_Rect> clips;
            Texture *texture;

    };
}

#endif