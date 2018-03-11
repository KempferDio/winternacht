#ifndef HEALTHCOMPONENT_H
#define HEALTHCOMPONENT_H
#include <Component.h>
#include <Log.h>

namespace Core {
    namespace Components {

       typedef struct Health : Component {
           int HP;
            Health() {
                Id = HEALTH_COMPONENT;
            }

       } Health;
       
    }
}

#endif