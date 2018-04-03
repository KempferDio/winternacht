#ifndef PAWN_DEF_H
#define PAWN_DEF_H
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