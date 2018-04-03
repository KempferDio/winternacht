#include <GameObjects/Pawn.h>

using namespace Core::GameObjects;

Pawn::Pawn()
{
}

Pawn::Pawn(Sprite *sprite)
    : GameObject(sprite)
{
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(100.0f, 10.0f);
    rigidBody = PhysicsManager::GetWorld()->CreateBody(&bodyDef);

    b2PolygonShape box;
    box.SetAsBox(1.0f, 1.0f);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &box;
    fixtureDef.density = 0.5f;
    fixtureDef.friction = 0.3f;

    rigidBody->CreateFixture(&fixtureDef);
}

void Pawn::Update()
{
    rect.x = rigidBody->GetPosition().x;
    rect.y = rigidBody->GetPosition().y;
}

void Pawn::MoveLeft()
{
    b2Vec2 vel = rigidBody->GetLinearVelocity();
    vel.x = b2Max(vel.x - 1.0f, 1.0f);
    Log::LogDebug("Move left. x is ",vel.x);
    rigidBody->SetLinearVelocity(vel);
}

void Pawn::MoveRight()
{
    b2Vec2 vel = rigidBody->GetLinearVelocity();
    vel.x = b2Max(vel.x + 1.0f, 1.0f);
    Log::LogDebug("Move right. x is ",vel.x);
    rigidBody->SetLinearVelocity(vel);
}

void Pawn::Jump()
{
    b2Vec2 vel = rigidBody->GetLinearVelocity();
    vel.y = b2Max(vel.y - 15.0f, 15.0f);
    rigidBody->SetLinearVelocity(vel);
}

void Pawn::Use()
{
    Log::LogDebug("Using...");
}