#ifndef BUFF_H
#define BUFF_H
#include <BaseInfo.h>

namespace Core {
    class Buff {
    public:
        int Id;
        BaseInfo info;
        int maxTime;
        int currentTime;
        int interval;

        Buff();
        Buff(BaseInfo info, int maxTime, int interval);
        void Tick();
        virtual ~Buff() {}
    };
}

#endif