#ifndef GAME_OBJECT_DECORATOR_H
#define GAME_OBJECT_DECORATOR_H
#include <GameObjects/IGameObject.h>

#include <Log.h>
/**
 * Behavior decorator for game object
*/

namespace Core {
    class GameObjectDecorator : public IGameObject {
    public:
        GameObjectDecorator(IGameObject* interface) {
            this->interface = interface;
        }
        ~GameObjectDecorator() {
            Log::LogDebug("GameObjectDecorator dtor");
            delete interface;
        }



    private:
        IGameObject* interface;
    };
}

#endif