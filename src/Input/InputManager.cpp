#include <Input/InputManager.h>

using namespace Core;

Command* InputManager::button_W;
Command* InputManager::button_A;
Command* InputManager::button_S;
Command* InputManager::button_D;
GameObject* InputManager::actor;
std::queue<Command*> InputManager::commandQueue;

/*void InputManager::SetButton(Command* button, CommandsList command) {
    button = CommandFactory::CreateCommand(command);
    button->execute();
}*/

void InputManager::SetButtonW(CommandsList command) {
    button_W = CommandFactory::CreateCommand(command);
}

void InputManager::SetButtonA(CommandsList command) {
    button_A = CommandFactory::CreateCommand(command);
}

void InputManager::SetButtonS(CommandsList command) {
    button_S = CommandFactory::CreateCommand(command);
}

void InputManager::SetButtonD(CommandsList command) {
    button_D = CommandFactory::CreateCommand(command);
}

void InputManager::SetActor(GameObject* newActor) {
    actor = newActor;
}

/*
    Executes all commands in queue
*/
void InputManager::HandleInput() {
    GetCommand();
    
    while(!commandQueue.empty()) {
        if(commandQueue.front() == NULL) {
            Log::LogError("Command is NULL");
            return;
        }

        Command* com = commandQueue.front();
        com->execute(actor);
        commandQueue.pop();
    }
}

void InputManager::Terminate() {

   delete button_A;
   delete button_D;
   delete button_S;
   delete button_W;
}

/*
    Fill command queue
*/
void InputManager::GetCommand() {
   
   SDL_Event e;
    while(SDL_PollEvent(&e)) {
        if(e.type == SDL_QUIT) {
            Renderer::SetWindowOpen(false);
        }

        else if(e.type == SDL_KEYDOWN) {
            if(e.key.keysym.sym == SDLK_w) {
                commandQueue.push(button_W);
                
            }
            if(e.key.keysym.sym == SDLK_a) {
                commandQueue.push(button_A);
            }
            if(e.key.keysym.sym == SDLK_s) {
                commandQueue.push(button_S);
            }
            if(e.key.keysym.sym == SDLK_d) {
                commandQueue.push(button_D);
            }
        }

    }
    
}

