#ifndef TILE_DEF_H
#define TILE_DEF_H
#include <GameObjects/Defs/GameObjectDef.h>
#include <Box2D/Box2D.h>

namespace Core
{
typedef struct PawnDef : GameObjectDef
{
    b2Body rigidBody;
} PawnDef;
}

#endif