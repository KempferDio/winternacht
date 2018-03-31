#ifndef PAWN_H
#define PAWN_H
#include <GameObjects/GameObject.h>
#include <Render/Sprite.h>
#include <SDL2/SDL.h>
#include <Box2D/Box2D.h>
#include <Physics/PhysicsManager.h>

namespace Core {
    namespace GameObjects {
        class Pawn : public GameObject {
        public:
            Pawn();
            Pawn(Sprite *sprite);
            Pawn(Sprite *sprite, SDL_Rect rect);

            void Update();

            void MoveLeft();
            void MoveRight();
            void Jump();
            void Use();

            //First physics
            b2Body *rigidBody;
        };
    }
}

#endif