#ifndef PHYSICS_MANAGER_H
#define PHYSICS_MANAGER_H
#include <Box2D/Box2D.h>
#include <Log.h>

namespace Core {
    class PhysicsManager {
        static b2World* world;
        static b2Vec2 gravity;
        static int32 velocityIterations; // default 6
        static int32 positionIterations; // default 2
        static float32 timeStep; //default 1.0f / 60.0f
    public:
        static void InitWorldPhysics();
        static void SetWorldGravity(b2Vec2 gravity);
        static b2World* GetWorld();

        static void UpdateWorld();
    };
}

#endif