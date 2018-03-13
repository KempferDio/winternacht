#include <Sprite.h>

using namespace Core;

/*
    clipCount - count of images on texture board
    clipSize - size of image box on texture board
*/
Sprite::Sprite(int clipRowCount, int clipColumnCount, int clipSize, SDL_Texture* texture) {
    this->texture = texture;
    this->clipSize = clipSize;
    this->clipRowCount = clipRowCount;
    this->clipColumnCount = clipColumnCount;

    int clipX = 0;
    int clipY = 0;
    for(int i = 0; i < clipColumnCount; i++) {
        for(int j = 0; j < clipRowCount; j++) {
            SDL_Rect rect;
            rect.x = clipX;
            rect.y = clipY;
            rect.w = clipSize;
            rect.h = clipSize;

            clips.push_back(rect);

            clipX += clipSize;
        }
        clipY += clipSize;
        clipX = 0;
    }
}

Sprite::~Sprite() {
    //~dtor
}

