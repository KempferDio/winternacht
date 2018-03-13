#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H
#include <Log.h>
#include <Command.h>
#include <SDL2/SDL.h>

namespace Core {
    class InputManager {
        public:
            void handleInput();
        private:
            Command* button_W;
            Command* button_A;
            Command* button_S;
            Command* button_D;
    };
}

#endif