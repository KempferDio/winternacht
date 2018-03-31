#ifndef JUMP_COMMAND_H
#define JUMP_COMMAND_H
#include <Input/Command.h>

namespace Core {
    class JumpCommand : public Command {
    public:
        JumpCommand() {}
        void execute(GameObjects::Pawn *actor);
    };
}

#endif