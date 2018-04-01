#ifndef GO_FACTORY_H
#define GO_FACTORY_H
#include <ResourceManager.h>
#include <GameObjects/GameObject.h>
#include <GameObjects/Pawn.h>
#include <GameObjects/Tile.h>
#include <GameObjects/Defs/GameObjectDef.h>

/**
 * Main factory class for game objects
*/
namespace Core
{
class GOFactory
{
    /**
         * Test methods
        */
    static GameObjects::Pawn *CreatePawn(GameObjectDef &def);
    static GameObjects::Tile *CreateTile(GameObjectDef &def);
};
}

#endif