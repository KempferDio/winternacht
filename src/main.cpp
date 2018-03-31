#include <unistd.h>
#include <chrono>
#include <iostream>

#include <Engine.h>
#include <Log.h>
#include <ResourceManager.h>
#include <Render/Renderer.h>

#include <Physics/PhysicsManager.h>

#include <GameObjects/IGameObject.h>
#include <GameObjects/GameObject.h>
#include <GameObjects/Behavior/TestBehavior.h>

#include <Input/InputManager.h>
#include <Input/CommandFactory.h>

#include <Box2D/Box2D.h>
#include <SDL2/SDL_image.h>

using namespace Core;

int main(int argc, char **argv)
{

#ifdef DEBUG
    Log::LogDebug("Debug mod is active");
    if (argc > 1 && std::string(argv[1]) == "-xterm")
    {
        if (::execl("/usr/bin/xterm", "xterm", "-e", argv[0], (char *)NULL))
        {
            std::perror("execl");
            return 1;
        }
    }
#endif

   /* b2Vec2 gravity(0.0f, -10.0f);

    b2World world(gravity);

    //static body
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.0f);

    b2Body* groundBody = world.CreateBody(&groundBodyDef);

    b2PolygonShape groundBox;
    groundBox.SetAsBox(50.0f, 10.0f);

    groundBody->CreateFixture(&groundBox, 0.0f);

    //dynamic body
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 4.0f);
    b2Body* body = world.CreateBody(&bodyDef);

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;

    body->CreateFixture(&fixtureDef);
    //

    float32 timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    for(int32 i = 0; i < 60; i++) {
        
        world.Step(timeStep, velocityIterations, positionIterations);
        b2Vec2 position = body->GetPosition();
        float32 angle = body->GetAngle();
        printf("%4.2f, %4.2f, %4.2f\n", position.x, position.y, angle);
    }*/


    Engine::InitSystem();

    PhysicsManager::InitWorldPhysics();

    ResourceManager::LoadTexture("res/textures/Dummy.png", "DummySheet");
    ResourceManager::LoadSpriteFromTexture("DummySheet", "Dummy");

    ResourceManager::CreatePawn("Dummy", "Dummy");
    ResourceManager::CreateTile("Box", "Dummy");
    

    ResourceManager::GetPawn("Dummy")->setPosition(60, 35);
    ResourceManager::GetPawn("Dummy")->setSize(64, 64);


    InputManager::SetButtonW(CommandsList::CMD_JUMP);
    InputManager::SetButtonA(CommandsList::CMD_MOVE_LEFT);
    InputManager::SetButtonS(CommandsList::CMD_USE);
    InputManager::SetButtonD(CommandsList::CMD_MOVE_RIGHT);

    InputManager::SetActor(ResourceManager::GetPawn("Dummy"));

    
    while (Renderer::IsWindowOpen())
    {
        InputManager::HandleInput();

        PhysicsManager::UpdateWorld();
        
        ResourceManager::GetPawn("Dummy")->Update();
        

        SDL_RenderClear(Renderer::GetRenderer());

        Renderer::Render("Dummy");
        Renderer::RenderTile("Box");

        SDL_RenderPresent(Renderer::GetRenderer());
    }

    Engine::Terminate();

    return 0;
}