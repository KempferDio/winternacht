#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H
#include <Log.h>
#include <Command.h>
#include <SDL2/SDL.h>
#include <Renderer.h>

namespace Core {
    class InputManager {
        public:
            
            void HandleInput();
            
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

            void Terminate();

            Command* button_W;
            Command* button_A;
            Command* button_S;
            Command* button_D;
            
        private:
            Command* GetCommand();
            
    };
}

#endif