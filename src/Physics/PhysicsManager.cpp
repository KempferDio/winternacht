#include <Physics/PhysicsManager.h>

using namespace Core;


b2Vec2 PhysicsManager::gravity(0.0f, -10.0f);
b2World* PhysicsManager::world;
int32 PhysicsManager::velocityIterations = 6; // default 6
int32 PhysicsManager::positionIterations = 2; // default 2
float32 PhysicsManager::timeStep = 1.0f / 60.0f; //default 1.0f / 60.0f


void PhysicsManager::InitWorldPhysics() {
    gravity = b2Vec2(0.0f, 0.1f);
    world = new b2World(gravity);
}

void PhysicsManager::SetWorldGravity(b2Vec2 gravity) {
    //
    world->SetGravity(gravity);
}

void PhysicsManager::UpdateWorld() {
    if(world == NULL) {
        Log::LogError("World is empty");
        return;
    }
    world->Step(timeStep, velocityIterations, positionIterations);
    
}

b2World* PhysicsManager::GetWorld() {
    return world;
}