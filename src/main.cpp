#include <SDL2/SDL.h>
#include <Log.h>
#include <chrono>

using namespace std::chrono;
using namespace Core;

bool Log::isLogFileWasCreated = false;
milliseconds Log::startTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

int main() {
    Log::makeNote("First");
    Log::makeNote("Second");
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        Log::makeNote("SDL Init error");
        return 1;
    }
    SDL_Window *window = SDL_CreateWindow("Shit", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_BORDERLESS);
    if(window == NULL) {
        Log::makeNote("Window wasn't created");
        return 1;
    }

    Log::makeNote("That's the test of Log system", "Yes");
    
    SDL_Delay(5000);

    SDL_Quit();

    return 0;
}