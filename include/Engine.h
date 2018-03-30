#ifndef ENGINE_H
#define ENGINE_H

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define APP_NAME "Winternacht"

#include <SDL2/SDL.h>
#include <Renderer.h>
#include <ResourceManager.h>
#include <Log.h>

namespace Core {
    class Engine {
        public:
            static int InitSystem();
            static void Terminate();
            static void Update();

        private:
    };
}

#endif