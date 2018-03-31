#include <Buff.h>

using namespace Core;

Buff::Buff() {

}

Buff::Buff(BaseInfo info, int maxTime, int interval) {
    this->info = info;
    this->maxTime = maxTime;
    this->interval = interval;
}