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

        void MoveLeft() {}
        void MoveRight() {
            interface->MoveRight();
            Log::LogDebug("Move right from GameObjectDecorator");
        }
        void Jump() {}
        void Use() {}

    private:
        IGameObject* interface;
    };
}

#endif