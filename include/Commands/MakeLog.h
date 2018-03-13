#ifndef MAKELOG_H
#define MAKELOG_H

#include <Log.h>
#include <Command.h>

namespace Core {
    namespace Commands {

        class MakeLog : public Command {
        public:
            void execute() {
                Log::makeNote("It's works");
            }
        };
        
    }
}


#endif
