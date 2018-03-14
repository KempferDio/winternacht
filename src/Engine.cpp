#include <Engine.h>

using namespace Core;

int Engine::InitSystem() {
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        Log::LogError("SDL can't init");
        return 1;
    }
    
    return 0;
}

void Engine::Terminate() {
    SDL_Quit();
}