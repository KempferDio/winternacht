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

        void MoveLeft() {
            GameObjectDecorator::MoveLeft();
        }
        void MoveRight() {
            GameObjectDecorator::MoveRight();
            Log::LogDebug("Move right from TestBehavior");
        }
        void Jump() {
            GameObjectDecorator::Jump();
        }
        void Use() {
            GameObjectDecorator::Use();
        }

        void UnrealSkill() {
            Log::LogDebug("From Test Behavior");
        }
    };
}

#endif