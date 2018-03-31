#ifndef TEST_BEHAVIOR_H
#define TEST_BEHAVIOR_H
#include <GameObjects/IGameObject.h>
#include <GameObjects/GameObjectDecorator.h>
#include <Log.h>

namespace Core {
    class TestBehavior : public GameObjectDecorator {
    public:
        TestBehavior(IGameObject* interface) : GameObjectDecorator(interface) {}
        ~TestBehavior() {
            Log::LogDebug("TestBehavior dtor");
        }

    };
}

#endif