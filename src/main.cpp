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

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 800

using namespace Core;


bool Log::isLogFileWasCreated = false;
std::chrono::milliseconds Log::startTime =
 std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());

int main(int argc, char** argv) {
    
#ifdef DEBUG
    Log::LogDebug("Debug mod is active");
    if(argc > 1 && std::string(argv[1]) == "-xterm") {
        if(::execl("/usr/bin/xterm", "xterm", "-e", argv[0], (char*)NULL)) {
            std::perror("execl");
            return 1;
        }
    }
#endif

    Engine::InitSystem();
    Renderer::InitRenderer("Winternacht", SCREEN_WIDTH, SCREEN_HEIGHT);
    ResourceManager::InitManager(Renderer::GetRenderer());
    ResourceManager::LoadTexture("res/textures/dummy.png", "DummySheet");
    ResourceManager::LoadSpriteFromTexture("DummySheet", "Dummy", 8, 1, 64);
    ResourceManager::CreateGameObject("Dummy", "Dummy");

    ResourceManager::GetGameObject("Dummy")->setPosition(60, 35);
    ResourceManager::GetGameObject("Dummy")->setSize(64, 64);

    SDL_Event e;
    while(Renderer::IsWindowOpen()) {
        SDL_RenderClear(Renderer::GetRenderer());    

        while(SDL_PollEvent(&e)) {
            if(e.type == SDL_QUIT) {
                Renderer::SetWindowOpen(false);
            }

            else if(e.type == SDL_KEYDOWN) {
                if(e.key.keysym.sym == SDLK_w) {
                    ResourceManager::GetGameObject("Dummy")->addPosition(0, -1);
                }
                if(e.key.keysym.sym == SDLK_a) {
                    ResourceManager::GetGameObject("Dummy")->addPosition(-1, 0);
                }
                if(e.key.keysym.sym == SDLK_s) {
                    ResourceManager::GetGameObject("Dummy")->addPosition(0, 1);
                }
                if(e.key.keysym.sym == SDLK_d) {
                    ResourceManager::GetGameObject("Dummy")->addPosition(1, 0);
                }
            } 
        }

        Renderer::Render("Dummy");

        SDL_RenderPresent(Renderer::GetRenderer());
    }

    ResourceManager::FreeMemory();
    ResourceManager::Terminate();
    Renderer::Terminate();
    Engine::Terminate();

    return 0;
}