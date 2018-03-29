#include <Queue.h>

using namespace Core;

template<typename T>
Queue<T>::Queue() {
    currentItem = -1;
}

template<typename T>
Queue<T>::~Queue() {
    Log::LogInfo("Queue if dead");
}

template<typename T>
void Queue<T>::push(T item) {
    if(isFull()) {
        Log::LogInfo("Queue is full");
        return;
    }

    currentItem++;
    data[currentItem] = item;
} 

template<typename T>
T Queue<T>::pop() {
    if(isEmpty()) {
        Log::LogInfo("Queue is empty");
        return;
    }
    
    T item = data[currentItem];
    currentItem--;
    return item;
}

template<typename T>
T Queue<T>::peek() {
    if(isEmpty()) {
        Log::LogInfo("Queue is empty");
        return;
    }

    return data[currentItem];
}

template<typename T>
bool Queue<T>::isFull() {
    if(currentItem == MAX_QUEUE_SIZE - 1) {
        return true;
    }

    return false;

}

template<typename T>
bool Queue<T>::isEmpty() {
    if(currentItem == -1) {
        return true;
    }

    return false;
}