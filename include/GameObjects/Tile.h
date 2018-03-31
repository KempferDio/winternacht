#ifndef TILE_H
#define TILE_H
#include <GameObjects/GameObject.h>
#include <Render/Sprite.h>
#include <SDL2/SDL.h>
#include <Box2D/Box2D.h>
#include <Physics/PhysicsManager.h>

namespace Core {
    namespace GameObjects {
        //All types of tiles
        enum TileType {
            TILE_VOID,
            TILE_GROUND
        };

        class Tile : public GameObject {
        public:
            Tile();
            Tile(Sprite *sprite);
            Tile(Sprite *sprite, SDL_Rect rect);
            int Type;
            int Solidity;

            b2Body* rigidBody;

        };

    }
}

#endif