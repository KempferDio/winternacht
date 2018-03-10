#include <SDL2/SDL.h>
#include <Log.h>
#include <chrono>

using namespace Core;
using namespace std::chrono;

bool Log::isLogFileWasCreated = false;
milliseconds Log::startTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

int main() {

#ifdef DEBUG
    Log::makeNote("Debug mode active!", "main");
#endif

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        Log::makeNote("SDL Init error");
        return 1;
    }
    Log::makeNote("End of init");

    SDL_Window *window = SDL_CreateWindow("Winternacht", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if(window == NULL) {
        Log::makeNote("Window couldn't created");
        return 1;
    }
    Log::makeNote("Start");
    
    SDL_Surface *screen = SDL_GetWindowSurface(window);
    Uint32 white = SDL_MapRGB(screen->format, 255, 255, 255);

    SDL_FillRect(screen, NULL, white);

    SDL_UpdateWindowSurface(window);

    SDL_Surface *sprite = SDL_LoadBMP("../res/textures/image.bmp");
    if(sprite == NULL) {
        Log::makeNote("Sprite couldn't load", "main");
    }

    SDL_BlitSurface(sprite, NULL, screen, NULL);
    Log::makeNote("BlitSurface");

    SDL_Event e;
    bool running = true;
    while(running) {
        
        while(SDL_PollEvent(&e)) {
            switch(e.type) {
                case SDL_QUIT:
                running = false;
                break;
            }
        }
    }
    
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}