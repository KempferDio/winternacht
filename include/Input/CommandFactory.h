#ifndef COMMAND_FACTORY_H
#define COMMAND_FACTORY_H
#include <memory>
#include <Input/Command.h>
#include <Input/Commands/MoveCommand.h>
#include <Input/Commands/MoveLeftCommand.h>
#include <Input/Commands/MoveRightCommand.h>
#include <Input/Commands/JumpCommand.h>
#include <Input/Commands/UseCommand.h>

namespace Core
{

enum CommandsList
{
    MOVE_COMMAND,
    CMD_MOVE_LEFT,
    CMD_MOVE_RIGHT,
    CMD_JUMP,
    CMD_USE
};

/*
        Simple command factory
*/
class CommandFactory
{
  public:
    static Command* CreateCommand(CommandsList command);

};
}

#endif