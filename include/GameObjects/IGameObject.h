#ifndef IGAME_OBJECT_H
#define IGAME_OBJECT_H
#include <Log.h>
/**
 * Pure game object interface
 * Needed for decorator
 * It's useless for now 
*/

namespace Core {
    class IGameObject {
    public:
        /**
         * Base game object methods
        */
        IGameObject() {}
        virtual ~IGameObject() {}
        
        virtual void MoveLeft() = 0;
        virtual void MoveRight() = 0;
        virtual void Jump() = 0;
        virtual void Use() = 0;
        
    };
}

#endif