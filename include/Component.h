#ifndef COMPONENT_H
#define COMPONENT_H
#include <Log.h>

#define HEALTH_COMPONENT 0
#define SPRITE_COMPONENT 1
#define TRANSFORM_COMPONENT 2

namespace Core {

    typedef struct Component {
        int Id;
        Component() {}
        virtual ~Component() {}
    } Component;
    
}

#endif