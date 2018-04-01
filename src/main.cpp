#include <unistd.h>
#include <chrono>
#include <iostream>

#include <Box2D/Box2D.h>
#include <SDL2/SDL_image.h>

#include <Engine.h>
#include <Log.h>
#include <ResourceManager.h>

#include <Render/Renderer.h>
#include <Render/DebugRender.h>

#include <Physics/PhysicsManager.h>

#include <GameObjects/IGameObject.h>
#include <GameObjects/GameObject.h>
#include <GameObjects/Behavior/TestBehavior.h>

#include <Input/InputManager.h>
#include <Input/CommandFactory.h>

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
    Engine::InitSystem();

    PhysicsManager::InitWorldPhysics();

    Core::Debug::DebugRender dRender;
    PhysicsManager::GetWorld()->SetDebugDraw(&dRender);
    uint32 flags = 0;
    flags += b2Draw::e_shapeBit;
    flags += b2Draw::e_pairBit;
    flags += b2Draw::e_jointBit;
    flags += b2Draw::e_centerOfMassBit;
    flags += b2Draw::e_aabbBit;

    dRender.SetFlags(flags);

    ResourceManager::LoadTexture("res/textures/Dummy.png", "DummySheet");
    ResourceManager::LoadSpriteFromTexture("DummySheet", "Dummy");

    ResourceManager::CreatePawn("Dummy", "Dummy");
    ResourceManager::CreateTile("Box", "Dummy");

    ResourceManager::GetPawn("Dummy")->setSize(64, 64);
    ResourceManager::GetTile("Box")->setSize(150, 20);

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

        PhysicsManager::GetWorld()->DrawDebugData();

        SDL_RenderPresent(Renderer::GetRenderer());
    }

    Engine::Terminate();

    return 0;
}