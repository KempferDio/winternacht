#ifndef COMMAND_H
#define COMMAND_H
#include <GameObjects/Pawn.h>
#include <Log.h>

namespace Core {

    class Command {
    public:
        Command() {}
        virtual void execute(GameObjects::Pawn* actor) = 0;
        virtual ~Command() {}
    };
    
}

#endif