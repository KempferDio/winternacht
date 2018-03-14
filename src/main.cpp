#include <unistd.h>
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

int main(int argc, char** argv) {
    
#ifdef DEBUG
    Log::makeNote("Debug mode active!", "main");
    if(argc > 1 && std::string(argv[1]) == "-xterm") {
        if(::execl("/usr/bin/xterm", "xterm", "-e", argv[0], (char*)NULL)) {
            std::perror("execl");
            return 1;
        }
    }
#endif
    int x = 2;
    int y = 24;
    std::string shit = "343";
    Log::LogInfo("That shit is great", x, y, shit, 43 , 54);
    Log::LogWarning("Shet", 34, 353, 36, 54.5);
    Log::LogError("That shit is great", x, y, shit);
    Log::LogDebug("That shit is great", x, y, shit);

    Engine::InitSystem();
    Renderer::InitRenderer("Winternacht", SCREEN_WIDTH, SCREEN_HEIGHT);
    ResourceManager::InitManager(Renderer::GetRenderer());

    ResourceManager::LoadTexture("res/textures/dummy.png", "DummySheet");
    ResourceManager::LoadSpriteFromTexture("DummySheet", "Dummy", 8, 1, 64);
    
    GameObject object;
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = 800;
    rect.h = 300;
    SDL_Event e;
    while(Renderer::IsWindowOpen()) {
        SDL_RenderClear(Renderer::GetRenderer());    

        while(SDL_PollEvent(&e)) {
            if(e.type == SDL_QUIT) {
                Renderer::SetWindowOpen(false);
            }
        }

        SDL_RenderCopy(Renderer::GetRenderer(),
        ResourceManager::GetSprite("Dummy")->texture,
        NULL,
        &rect);
        
        
        SDL_RenderPresent(Renderer::GetRenderer());
    }

    Renderer::Terminate();
    ResourceManager::Terminate();
    Engine::Terminate();

    return 0;
}