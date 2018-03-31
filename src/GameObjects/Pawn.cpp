#include <GameObjects/Pawn.h>

using namespace Core::GameObjects;

Pawn::Pawn() {

}

Pawn::Pawn(Sprite *sprite)
 : GameObject(sprite) {
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

Pawn::Pawn(Sprite *sprite, SDL_Rect rect)
 : GameObject(sprite, rect) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 4.0f);
    rigidBody = PhysicsManager::GetWorld()->CreateBody(&bodyDef);

    b2PolygonShape box;
    box.SetAsBox(1.0f, 1.0f);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &box;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;

    rigidBody->CreateFixture(&fixtureDef);
}

void Pawn::Update() {
    if(rigidBody == NULL) {
        Log::LogDebug("Alles kaput");
        return;
    }
    rect.x = rigidBody->GetPosition().x;
    rect.y = rigidBody->GetPosition().y;
    
}

void Pawn::MoveLeft() {
    addPosition(-1, 0);
}

void Pawn::MoveRight() {
    addPosition(1, 0);
}

void Pawn::Jump() {
    addPosition(0, -1);
}

void Pawn::Use() {
    Log::LogDebug("Using...");
}