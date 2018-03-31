#include <Render/Sprite.h>

using namespace Core;

/*
    Creates sprite from texture with same width and height
*/
Sprite::Sprite(int clipRowCount, int clipColumnCount, int clipSize, Texture* texture) {
    this->texture = texture;
    this->clipSize = clipSize;
    this->clipRowCount = clipRowCount;
    this->clipColumnCount = clipColumnCount;
    this->clipWidth = clipSize;
    this->clipHeight = clipSize;

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

//Creates sprite from texture with different width and height
Sprite::Sprite(int clipRowCount, int clipColumnCount, int clipWidth, int clipHeight, Texture* texture) {
    this->texture = texture;
    this->clipSize = 0;
    this->clipRowCount = clipRowCount;
    this->clipColumnCount = clipColumnCount;
    this->clipWidth = clipWidth;
    this->clipHeight = clipHeight;
    
    int clipX = 0;
    int clipY = 0;
    for(int i = 0; i < clipColumnCount; i++) {
        for(int j = 0; j < clipRowCount; j++) {
            SDL_Rect rect;
            rect.x = clipX;
            rect.y = clipY;
            rect.w = clipWidth;
            rect.h = clipHeight;

            clips.push_back(rect);

            clipX += clipWidth;
        }
        clipY += clipHeight;
        clipX = 0;
    }
}

//Creates sprite from full texture
Sprite::Sprite(Texture *texture) {
    this->texture = texture;
    this->clipSize = 1;
    this->clipRowCount = 1;
    this->clipColumnCount = 1;
    this->clipWidth = texture->rect.w;
    this->clipHeight = texture->rect.h;

    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = clipWidth;
    rect.h = clipHeight;

    clips.push_back(rect);
}

Sprite::~Sprite() {
    //~dtor
}

