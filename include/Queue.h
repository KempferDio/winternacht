#ifndef QUEUE_H
#define QUEUE_H
#define MAX_QUEUE_SIZE 4

#include <Log.h>

namespace Core {

    template<typename T>
    class Queue {
    public:

        typedef struct QueueItem {
            
            T data;
            QueueItem *next;

        } QueueItem;


        int currentItem;
        int size;
        T data[MAX_QUEUE_SIZE];

        Queue() {
            size = 0;
            currentItem = -1;
        }

        ~Queue() {
            Log::LogInfo("Queue if dead");
        }

        void push(T item) {
            if(isFull()) {
                Log::LogInfo("Queue is full");
                return;
            }
            size++;
            data[size] = item;
        } 

        T pop() {
            if(isEmpty()) {
                Log::LogInfo("Queue is empty");
                return NULL;
            }
            T item = data[currentItem];
            currentItem--;
            return item;
        }

        T peek() {
            if(isEmpty()) {
                Log::LogInfo("Queue is empty");
                return NULL;
            }
            return data[currentItem];
        }

        bool isFull() {
            if(currentItem == MAX_QUEUE_SIZE - 1) {
                return true;
            }
            return false;
        }

        bool isEmpty() {
            if(currentItem == -1) {
                return true;
            }
            return false;
        }

       
    };
}

#endif