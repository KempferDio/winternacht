#ifndef QUEUE_H
#define QUEUE_H
#define MAX_QUEUE_SIZE 128

#include <Log.h>

namespace Core {
    template<typename T>
    class Queue {
    public:
        Queue();
        ~Queue();

        int currentItem;
        
       
        T data[MAX_QUEUE_SIZE];
        
       
        void push(T item);

        
        T pop();

        
        T peek();
        bool isFull();
        bool isEmpty();
    };
}

#endif