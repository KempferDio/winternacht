#include <Engine.h>
#include <ResourceManager.h>
#include <Renderer.h>
#include <Log.h>
#include <chrono>
#include <SDL2/SDL_image.h>
#include <iostream>

#include <Game/GameObject.h>
#include <Component.h>
#include <Components/Health.h>
#include <Components/Sprite.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

using namespace Core;
using namespace std::chrono;

bool Log::isLogFileWasCreated = false;
milliseconds Log::startTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

int main() {
#ifdef DEBUG
    Log::makeNote("Debug mode active!", "main");
#endif
    GameObject newGO;
    newGO.addComponent<Components::Health>(HEALTH_COMPONENT);
    newGO.addComponent<Components::Health>(HEALTH_COMPONENT);
    newGO.getComponent<Components::Health>(HEALTH_COMPONENT)->HP = 53;
    std::cout << newGO.getComponent<Components::Health>(HEALTH_COMPONENT)->HP << std::endl;
    

    Engine::InitSystem();
    Renderer::InitRenderer("Winternacht", SCREEN_WIDTH, SCREEN_HEIGHT);
    ResourceManager::InitManager(Renderer::GetRenderer());

    ResourceManager::LoadTexture("../res/textures/dummy.png", "Dummy");

    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = 800;
    rect.h = 200;

    SDL_Event e;
    while(Renderer::IsWindowOpen()) {
        while(SDL_PollEvent(&e)) {
            switch(e.type) {
                case SDL_QUIT:
                    Renderer::SetWindowOpen(false);
                break;
            }
        }
        
        SDL_RenderClear(Renderer::GetRenderer());
        SDL_RenderCopy(Renderer::GetRenderer(), ResourceManager::GetTexture("Dummy"), NULL, &rect);
        SDL_RenderPresent(Renderer::GetRenderer());
    }

    Renderer::Terminate();
    ResourceManager::Terminate();
    Engine::Terminate();

    return 0;
}