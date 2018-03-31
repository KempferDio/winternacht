#ifndef MOVE_RIGHT_COMMAND_H
#define MOVE_RIGHT_COMMAND_H
#include <Input/Command.h>
#include <Log.h>

namespace Core {
    class MoveRightCommand : public Command {
    public:

        MoveRightCommand() {}
        ~MoveRightCommand() {}
        void execute(GameObjects::Pawn *actor);
    };
}

#endif