#ifndef COMMAND_H
#define COMMAND_H

namespace Core {

    class Command {
    public:
        Command() {}
        virtual void execute() = 0;
        virtual ~Command() { }
    };
    
}

#endif