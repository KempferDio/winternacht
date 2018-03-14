#include <GameObject.h>

using namespace Core;

GameObject::GameObject() {

}

void GameObject::setCurrentState(GameObjectState newState) {
    currentState = newState;
}

GameObjectState GameObject::getCurrentState() {
    return currentState;
}

int GameObject::getID() {
    return ID;
}