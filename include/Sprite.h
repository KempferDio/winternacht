#ifndef SPRITE_H
#define SPRITE_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <Log.h>
#include <Renderer.h>
#include <vector>

namespace Core {
    class Sprite {
        public:
            Sprite() {}
            Sprite(int clipRowCount, int clipColumnCount, int clipSize, SDL_Texture* texture);
            ~Sprite();
            
            void Render(int x, int y, SDL_Rect* clip);
            void free();

            int clipRowCount;
            int clipColumnCount;
            int clipSize;
            std::vector<SDL_Rect> clips;
            SDL_Texture *texture;

    };
}

#endif