#include <GameObject.h>

using namespace Core;

GameObject::GameObject() {
    this->sprite = NULL;
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = 0;
    rect.h = 0;
    this->rect = rect;
}

GameObject::GameObject(Sprite *sprite) {
    this->sprite = sprite;
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = 0;
    rect.h = 0;
    this->rect = rect;
}

GameObject::GameObject(Sprite *sprite, SDL_Rect rect) {
    this->sprite = sprite;
    this->rect = rect;
}

void GameObject::setCurrentState(GameObjectState newState) {
    currentState = newState;
}

GameObjectState GameObject::getCurrentState() {
    return currentState;
}

void GameObject::setSprite(Sprite* sprite) {
    this->sprite = sprite;
}

void GameObject::setPosition(int x, int y) {
    this->rect.x = x;
    this->rect.y = y;
}

void GameObject::setSize(int w, int h) {
    this->rect.w = w;
    this->rect.h = h;
}

void GameObject::addPosition(int x, int y) {
    this->rect.x += x;
    this->rect.y += y;
}

void GameObject::addSize(int w, int h) {
    this->rect.w += w;
    this->rect.h += h;
}

int GameObject::getID() {
    return ID;
}