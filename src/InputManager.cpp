/*#include <InputManager.h>

using namespace Core;

Command* InputManager::button_W;
Command* InputManager::button_A;
Command* InputManager::button_S;
Command* InputManager::button_D;

template <class T>
void InputManager::SetButtonW(T newCommand) {
    button_W = newCommand;
}
template <class T>
void InputManager::SetButtonA(T newCommand) {
    button_A = newCommand;
}
template <class T>
void InputManager::SetButtonS(T newCommand) {
    button_S = newCommand;
}
template <class T>
void InputManager::SetButtonD(T newCommand) {
    button_D = newCommand;
}

Command* InputManager::HandleInput() {
    SDL_Event e;
    while(SDL_PollEvent(&e)) {
        if(e.type == SDL_KEYDOWN) {
            switch(e.key.keysym.sym) {
                //W
                case SDLK_w: 
                return button_W;
                //A
                case SDLK_a:
                return button_A;
                //S    
                case SDLK_s:
                return button_S;
                //D
                case SDLK_d:
                return button_D;
            }
        }
    }

    return NULL;
}*/