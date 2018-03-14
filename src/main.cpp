#include <Engine.h>
#include <ResourceManager.h>
#include <Renderer.h>
#include <InputManager.h>
#include <Log.h>
#include <chrono>
#include <SDL2/SDL_image.h>
#include <iostream>

#include <GameObject.h>

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
    
    GameObject object;

    while(Renderer::IsWindowOpen()) {
        SDL_RenderClear(Renderer::GetRenderer());    

        
        
        
        SDL_RenderPresent(Renderer::GetRenderer());
    }

    Renderer::Terminate();
    ResourceManager::Terminate();
    Engine::Terminate();

    return 0;
}