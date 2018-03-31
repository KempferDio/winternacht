#ifndef PARTICLES_H
#define PARTICLES_H
#include <Sprite.h>
#include <GameObject.h>
#include <SDL2/SDL.h>

namespace Core {
    class Particles : public GameObject {
    public:
        Particles(int x, int y);

    private:
        
        Sprite *sprite;
    };
}

#endif