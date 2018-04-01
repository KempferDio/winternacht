#include <GameObjects/Tile.h>

using namespace Core::GameObjects;

Tile::Tile() {}

Tile::Tile(Sprite *sprite)
    : GameObject(sprite)
{
    b2BodyDef bodyDef;
    bodyDef.position.Set(100.0f, 200.0f);
    rigidBody = PhysicsManager::GetWorld()->CreateBody(&bodyDef);

    b2PolygonShape box;
    box.SetAsBox(150.0f, 10.0f);

    rigidBody->CreateFixture(&box, 0.0f);

    rect.x = rigidBody->GetPosition().x;
    rect.y = rigidBody->GetPosition().y;
}

Tile::Tile(Sprite *sprite, SDL_Rect rect)
    : GameObject(sprite, rect)
{
    b2BodyDef bodyDef;
    bodyDef.position.Set(0.0f, -10.0f);
    rigidBody = PhysicsManager::GetWorld()->CreateBody(&bodyDef);

    b2PolygonShape box;
    box.SetAsBox(150.0f, 10.0f);

    rigidBody->CreateFixture(&box, 0.0f);

    rect.x = rigidBody->GetPosition().x;
    rect.y = rigidBody->GetPosition().y;
}