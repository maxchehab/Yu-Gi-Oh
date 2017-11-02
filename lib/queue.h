#ifndef QUEUE_H
#define QUEUE_H

class Queue{
    private:
        int *queueArray;
        int queueSize;
        int front;
        int rear;
        int numItems;
    public:
        //Constructor
        Queue(int);

        //Destructor
        ~Queue();

        //Queue operations
        void enqueue(int);
        void dequeue(int&);
        bool isEmpty() const;
        bool isFull() const;
        void clear();
};

Queue::Queue(int size){
    queueArray = new int[size];
    queueSize = size;
    front = -1;
    rear = -1;
    numItems = 0;
}

Queue::~Queue(){
    delete []queueArray;
}

void Queue::enqueue(int num){
    if(!isFull()){
        //Calculate the new rear position
        rear = (rear + 1) % queueSize;
        //Insert new item
        queueArray[rear] = num;
        //Update item count
        numItems++;
    }
}

void Queue::dequeue(int &num){
    if(!isEmpty()){
        //Move the front
        front = (front + 1) % queueSize;
        //Retrieve the front item
        num = queueArray[front];
        //Update item count
        numItems--;
    }
}

bool Queue::isEmpty() const{
    return !numItems;
}

bool Queue::isFull() const{
    return (numItems >= queueSize);
}

void Queue::clear(){
    front = queueSize - 1;
    rear = queueSize - 1;
    numItems = 0;
}

#endif