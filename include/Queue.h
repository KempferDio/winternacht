#ifndef QUEUE_H
#define QUEUE_H
#define MAX_QUEUE_SIZE 128
#include <Log.h>

namespace Core {

    template<typename T>
    class Queue {

        T data[MAX_QUEUE_SIZE];

        void push(T item) {
            if(isFull) {
                Log::LogWarning("Queue is full");
                return;
            }
        }
        
        T pop();

        T peek();

        bool isEmpty() {
            if(data[0] == NULL) {
                return true;
            }

            return false;
        }
        bool isFull() {
            if(data[MAX_QUEUE_SIZE] == NULL) {
                return false;
            }

            return true;
        }
    };
}

#endif