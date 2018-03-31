#include <unistd.h>
#include <Engine.h>
#include <ResourceManager.h>
#include <Renderer.h>

#include <Log.h>
#include <chrono>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <GameObjects/GameObject.h>
#include <Queue.h>

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
    
    ResourceManager::LoadTexture("res/textures/Dummy.png", "DummySheet");
    ResourceManager::LoadSpriteFromTexture("DummySheet", "Dummy");
    ResourceManager::CreateGameObject("Dummy", "Dummy");

    ResourceManager::GetGameObject("Dummy")->setPosition(60, 35);
    ResourceManager::GetGameObject("Dummy")->setSize(64, 64);


    InputManager::SetButtonW(CommandsList::MOVE_COMMAND);
    InputManager::SetButtonA(CommandsList::MOVE_COMMAND);
    InputManager::SetButtonS(CommandsList::MOVE_COMMAND);
    InputManager::SetButtonD(CommandsList::MOVE_COMMAND);

    InputManager::SetActor(ResourceManager::GetGameObject("Dummy"));

    //SDL_Event e;
    while (Renderer::IsWindowOpen())
    {
        SDL_RenderClear(Renderer::GetRenderer());

        InputManager::HandleInput();

        Renderer::Render("Dummy");

        SDL_RenderPresent(Renderer::GetRenderer());
    }

    Engine::Terminate();

    return 0;
}