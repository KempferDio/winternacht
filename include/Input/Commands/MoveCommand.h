#ifndef MOVE_COMMAND_H
#define MOVE_COMMAND_H
#include <Input/Command.h>
#include <Log.h>


namespace Core {
    class MoveCommand : public Command {
    public:
        MoveCommand() {}
        ~MoveCommand() {}

        void execute(GameObjects::Pawn *actor);
    private:
    };
}

#endif