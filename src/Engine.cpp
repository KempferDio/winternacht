#include <Engine.h>

using namespace Core;

int Engine::InitSystem() {
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        Log::LogError("SDL can't init");
        return 1;
    }

    Renderer::InitRenderer(APP_NAME, SCREEN_WIDTH, SCREEN_HEIGHT);
    ResourceManager::InitManager(Renderer::GetRenderer());
    return 0;
}

void Engine::Terminate() {
    ResourceManager::FreeMemory();
    ResourceManager::Terminate();
    Renderer::Terminate();
    SDL_Quit();
}