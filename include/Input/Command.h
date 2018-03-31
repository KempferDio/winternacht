#ifndef COMMAND_H
#define COMMAND_H
#include <GameObjects/GameObject.h>
#include <Log.h>

namespace Core {

    class Command {
    public:
        Command() {}
        virtual void execute(GameObject* actor) = 0;
        virtual ~Command() {}
    };
    
}

#endif