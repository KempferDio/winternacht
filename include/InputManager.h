#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H
#include <Log.h>
#include <Command.h>
#include <SDL2/SDL.h>
#include <Renderer.h>

namespace Core {
    class InputManager {
        public:
            Command* HandleInput() {
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
            
            template <class T>
            void SetButtonW(T newCommand) {
                button_W = dynamic_cast<Command*>(newCommand);
            }
            template <class T>
            void SetButtonA(T newCommand) {
                button_A =  dynamic_cast<Command*>(newCommand);
            }
            template <class T>
            void SetButtonS(T newCommand) {
                button_S =  dynamic_cast<Command*>(newCommand);
            }
            template <class T>
            void SetButtonD(T newCommand) {
                button_D =  dynamic_cast<Command*>(newCommand);
            }
            
        private:
            Command* button_W;
            Command* button_A;
            Command* button_S;
            Command* button_D;
    };
}

#endif