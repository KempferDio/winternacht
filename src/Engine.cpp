#include <Engine.h>

using namespace Core;

int Engine::InitSystem() {
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        Log::makeNote("SDL couldn't init", "Engine::initSystem");
        return -1;
    }
    
    return 0;
}

void Engine::Terminate() {
    SDL_Quit();
}