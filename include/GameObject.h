#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SDL2/SDL.h>
#include <Log.h>
#include <Sprite.h>

namespace Core {

    enum GameObjectState {
        ALIVE,
        DEAD
    };

    class GameObject {
    public:
        GameObject();
        GameObject(Sprite *sprite);
        GameObject(Sprite *sprite, SDL_Rect rect);
        
        //
        ~GameObject() {
            Log::LogInfo("Object was destroyed");
        }
        
        SDL_Rect rect;
        Sprite *sprite;
        
        GameObjectState getCurrentState();
        void setSprite(Sprite *sprite);
        void setCurrentState(GameObjectState newState);
        void setPosition(int x, int y);
        void setSize(int w, int h);
        void addPosition(int x, int y);
        void addSize(int w, int h);
        int getID();

    private:
        GameObjectState currentState;
        int ID;
    };
}

#endif