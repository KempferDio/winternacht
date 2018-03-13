#ifndef COMMAND_H
#define COMMAND_H

namespace Core {

    class Command {
        Command();
        virtual ~Command();
        virtual void execute() = 0;
    };
    
}

#endif