#ifndef QUEUE_H
#define QUEUE_H
#define MAX_QUEUE_SIZE 128

namespace Core {
    template<typename T>
    class Queue {
        T data[MAX_QUEUE_SIZE];
        void push(T item);
        T pop();
        T peek();
    };
}

#endif