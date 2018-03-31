#include <Input/CommandFactory.h>

using namespace Core;

Command* CommandFactory::CreateCommand(CommandsList command)
{
    switch (command)
    {
    case MOVE_COMMAND:
        return new MoveCommand();
    case CMD_MOVE_LEFT:
        return new MoveLeftCommand();
    case CMD_MOVE_RIGHT:
        return new MoveRightCommand();
    case CMD_JUMP:
        return new JumpCommand();
    case CMD_USE:
        return new UseCommand();
    }

    return NULL;
}