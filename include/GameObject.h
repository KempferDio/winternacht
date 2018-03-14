#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SDL2/SDL.h>



namespace Core {
    enum GameObjectState {
        ALIVE,
        DEAD
    };

    class GameObject {
    public:
        GameObject();
        
        SDL_Rect rect;
        
        GameObjectState getCurrentState();
        void setCurrentState(GameObjectState newState);
        int getID();

    private:
        GameObjectState currentState;
        int ID;
        
    };
}

#endif