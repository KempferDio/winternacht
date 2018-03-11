#include <Engine.h>
#include <ResourceManager.h>
#include <Renderer.h>
#include <Log.h>
#include <chrono>
#include <SDL2/SDL_image.h>


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
//SDL_ConvertSurface
//SDL_MapRGBA
//SDL_FillRect
//SDL_BlitScaled

    Engine::InitSystem();
    Renderer::InitRenderer("Winternacht", SCREEN_WIDTH, SCREEN_HEIGHT);
    ResourceManager::InitManager(Renderer::GetRenderer());

    ResourceManager::LoadTexture("../res/textures/dummy.png", "Dummy");

    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = 800;
    rect.h = 200;

    bool running = true;
    SDL_Event e;
    while(running) {

        while(SDL_PollEvent(&e)) {
            switch(e.type) {
                case SDL_QUIT:
                    running = false;
                break;
            }
        }

        SDL_RenderClear(Renderer::GetRenderer());

        SDL_RenderCopy(Renderer::GetRenderer(), ResourceManager::GetTexture("Dummy"), NULL, &rect);

        SDL_RenderPresent(Renderer::GetRenderer());

    }

    Renderer::Terminate();


    return 0;
}