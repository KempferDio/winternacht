#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <Component.h>
#include <Log.h>
#include <vector>
#include <memory>

namespace Core {
    class GameObject {
        public:
            GameObject() {}
            virtual ~GameObject() {}
            
            std::vector<Component*> _components;
            std::map<int, Component*> components;

            template <typename T>
            void addComponent(int componentId) {
                try {
                    Component* component = components.at(componentId);
                    if(component != NULL) {
                        Log::makeNote("Unable to add component. That component already exist");
                        return;
                    }
                } catch(std::out_of_range &ex) {
#ifdef DEBUG
                    Log::makeNote("Component was added");
#endif
                    Component* component = new T;
                    components.insert(std::pair<unsigned int, Component*>(component->Id, component));
                }
            }
\
            void removeComponent(int componentId) {
                components.erase(componentId);
            }

            template<typename T>
            T* getComponent(int componentId) {
                Component* component = components.at(componentId);
                T* returnedComponent = dynamic_cast<T*>(component);
                return returnedComponent;
            }
    };
}

#endif