#ifndef SPRITE_H
#define SPRITE_H

#include <Log.h>
#include <Render/Texture.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <vector>

namespace Core {
    class Sprite {
        public:
            Sprite() {}
            Sprite(Texture* texture);
            Sprite(int clipRowCount, int clipColumnCount, int clipSize, Texture* texture);
            Sprite(int clipRowCount, int clipColumnCount, int clipWidth, int clipHeight, Texture* texture);
            ~Sprite();

            int clipRowCount;
            int clipColumnCount;
            int clipSize;

            int clipWidth;
            int clipHeight;
            std::vector<SDL_Rect> clips;
            Texture *texture;

    };
}

#endif