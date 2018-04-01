#ifndef GAME_OBJECT_DEF_H
#define GAME_OBJECT_DEF_H
#include <string>
#include <Render/Sprite.h>
#include <SDL2/SDL.h>

namespace Core
{
typedef struct GameObjectDef
{
    std::string name;
    Sprite *sprite;
    SDL_Rect rect;
} GameObjectDef;
}

#endif