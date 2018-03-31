#include <Input/CommandFactory.h>

using namespace Core;

Command *CommandFactory::CreateCommand(CommandsList command)
{
    switch (command)
    {
    case MOVE_COMMAND:
        return new MoveCommand();
    case USE_COMMAND:
        return NULL; //FIX THIS
    }

    return NULL;
}