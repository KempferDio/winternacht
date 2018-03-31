#ifndef MOVE_LEFT_COMMAND_H
#define MOVE_LEFT_COMMAND_H
#include <Input/Command.h>

namespace Core {
    class MoveLeftCommand : public Command {
    public:

        MoveLeftCommand() {}
        void execute(GameObject *actor);
    };
}

#endif