#include "monster.h"

#ifndef QUEUE_H
#define QUEUE_H

class Queue{
    private:
        Monster *queueArray;
        int queueSize;
        int front;
        int rear;
    public:
        //Constructor
        Queue(int);

        //Destructor
        ~Queue();
        int length;
        
        //Queue operations
        void enqueue(Monster);
        void dequeue(Monster&);
        bool isEmpty() const;
        bool isFull() const;
        void clear();
};

Queue::Queue(int size){
    queueArray = new Monster[size];
    queueSize = size;
    front = -1;
    rear = -1;
    length = 0;
}

Queue::~Queue(){
    delete []queueArray;
}

void Queue::enqueue(Monster monster){
    if(!isFull()){
        //Calculate the new rear position
        rear = (rear + 1) % queueSize;
        //Insert new item
        queueArray[rear] = monster;
        //Update item count
        length++;
    }
}

void Queue::dequeue(Monster &monster){
    if(!isEmpty()){
        //Move the front
        front = (front + 1) % queueSize;
        //Retrieve the front item
        monster = queueArray[front];
        //Update item count
        length--;
    }
}

bool Queue::isEmpty() const{
    return !length;
}

bool Queue::isFull() const{
    return (length >= queueSize);
}

void Queue::clear(){
    front = queueSize - 1;
    rear = queueSize - 1;
    length = 0;
}

#endif