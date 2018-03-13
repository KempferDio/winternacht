#include <InputManager.h>

using namespace Core;

/*

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
}*/

Command* InputManager::HandleInput() {
   SDL_Event e;
    while(SDL_PollEvent(&e)) {
        if(e.type == SDL_QUIT) {
            Renderer::SetWindowOpen(false);
    }
    if(e.type == SDL_KEYDOWN) {
            switch(e.key.keysym.sym) {
                            //W
            case SDLK_w: 
            return button_W;
            }
        }
    }

    return NULL;

}

void InputManager::Terminate() {
    
}