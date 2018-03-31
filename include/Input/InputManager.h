#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H
#include <queue>
#include <SDL2/SDL.h>
#include <Renderer.h>
#include <Log.h>

#include <GameObjects/GameObject.h>

#include <Input/CommandFactory.h>
#include <Input/Command.h>

namespace Core
{
class InputManager
{
  public:
    static void HandleInput();

    static void Terminate();

    /*
        Fix that methods later
        
    */
    static void SetButtonW(CommandsList command);
    static void SetButtonA(CommandsList command);
    static void SetButtonS(CommandsList command);
    static void SetButtonD(CommandsList command);

    static void SetActor(GameObject* newActor);
    //static void SetButton(Command *button, CommandsList command);

    static Command *button_W;
    static Command *button_A;
    static Command *button_S;
    static Command *button_D;

  private:
    //Actor, who would be executing all commands
    static GameObject* actor;
    static std::queue<Command*> commandQueue;

    static void GetCommand();
};
}

#endif