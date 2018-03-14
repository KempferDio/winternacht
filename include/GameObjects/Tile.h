#ifndef TILE_H
#define TILE_H
#include <GameObject.h>


namespace Core {
    namespace GameObjects {
        //All types of tiles
        enum TileType {
            TILE_VOID,
            TILE_GROUND
        };

        class Tile : public GameObject {
        public:
            int Type;
            int Solidity;
        };

    }
}

#endif