#ifndef SPRITE_H
#define SPRITE_H
#include <Component.h>

namespace Core {
    namespace Components {

        typedef struct Sprite : Component {
            Sprite() {
                Id = SPRITE_COMPONENT;
            }
            int sprite;
        } Sprite;

    }
}

#endif