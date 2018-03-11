#ifndef ENGINE_H
#define ENGINE_H

#include <SDL2/SDL.h>
#include <Log.h>

namespace Core {
    class Engine {
        public:
            static int InitSystem();
            static void Terminate();

        private:
    };
}

#endif