#include "Customer.h"

const int MAX_QUEUE_SIZE = 20;

inline void error(char* str){
    printf("%s",str);
    exit(1);
}

class CustomerQueue{
    protected :
    int front;
    int rear;
    Customer data[MAX_QUEUE_SIZE];
    public :
    CustomerQueue(){ front = rear = 0; }
    ~CustomerQueue(){}
    bool isFull() { return (rear+1)%MAX_QUEUE_SIZE == front; }
    bool isEmpty() { return front == rear; }

    void enqueue(Customer e){
        if(isFull()){ error("QUEUE IS FULL\n"); }
        else { 
            rear = (rear+1)%MAX_QUEUE_SIZE;
            data[rear] = e; 
            }
    }
    Customer dequeue(){ 
        if(isEmpty()){ error("QUEUE IS EMPTY\n"); }
        else {
            front = (front+1)%MAX_QUEUE_SIZE;
            return data[front];
        }
    }
    Customer peek(){
        if(isEmpty()){ error("QUEUE IS EMPTY\n"); }
        else {
            front = (front+1)%MAX_QUEUE_SIZE;
            return data[front];
         }
    }
};
