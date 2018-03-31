#ifndef COMMAND_FACTORY_H
#define COMMAND_FACTORY_H
#include <Input/Command.h>
#include <Input/Commands/MoveCommand.h>

namespace Core
{

enum CommandsList
{
    MOVE_COMMAND,
    USE_COMMAND
};

/*
        Simple command factory
*/
class CommandFactory
{
  public:
    static Command *CreateCommand(CommandsList command);

};
}

#endif