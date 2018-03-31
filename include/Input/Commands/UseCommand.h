#ifndef USE_COMMAND_H
#define USE_COMMAND_H
#include <Input/Command.h>

namespace Core {
    class UseCommand : public Command {
    public:
        UseCommand() {}
        void execute(GameObject* actor);
    };
}

#endif