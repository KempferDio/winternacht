#include <Engine.h>
#include <ResourceManager.h>
#include <Renderer.h>
#include <InputManager.h>
#include <Log.h>
#include <chrono>
#include <SDL2/SDL_image.h>
#include <iostream>

#include <Game/GameObject.h>
#include <Component.h>
#include <Components/Health.h>
#include <Components/Sprite.h>

#include <Command.h>
#include <Commands/MakeLog.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

using namespace Core;


bool Log::isLogFileWasCreated = false;
std::chrono::milliseconds Log::startTime =
 std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());

int main() {
    
#ifdef DEBUG
    Log::makeNote("Debug mode active!", "main");
#endif
    Engine::InitSystem();
    Renderer::InitRenderer("Winternacht", SCREEN_WIDTH, SCREEN_HEIGHT);
    ResourceManager::InitManager(Renderer::GetRenderer());

    ResourceManager::LoadTexture("../res/textures/dummy.png", "DummySheet");
    ResourceManager::LoadSpriteFromTexture("DummySheet", "Dummy", 8, 1, 64);
    InputManager IM;

    Commands::MakeLog *comm = new Commands::MakeLog;
    IM.SetButtonW(comm);


    int clip = 0;
    while(Renderer::IsWindowOpen()) {
        Command* command = IM.HandleInput();
        if(command) {
            command->execute();
        }
        
        SDL_RenderClear(Renderer::GetRenderer());
        ResourceManager::GetSprite("Dummy").Render(ResourceManager::GetSprite("Dummy").clips[clip].x,
            ResourceManager::GetSprite("Dummy").clips[clip].y,
            &ResourceManager::GetSprite("Dummy").clips[clip]);

        
        SDL_RenderPresent(Renderer::GetRenderer());
    }
    delete comm;


    Renderer::Terminate();
    ResourceManager::Terminate();
    Engine::Terminate();

    return 0;
}