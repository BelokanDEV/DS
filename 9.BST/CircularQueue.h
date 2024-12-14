#include "BinaryNode.h"
#include <cstdlib>

const int MAX_QUEUE_SIZE = 100;

inline void error(const char* str){
    fprintf(stderr, "%s\n", str);
    exit(1);
};

class CircularQueue{
    int front;
    int rear;
    BinaryNode* data[MAX_QUEUE_SIZE];
public :
    CircularQueue()
    : front(0), rear(0) {}
    ~CircularQueue(){}
    bool isEmpty(){return front==rear;}
    bool isFull(){return (rear+1)%MAX_QUEUE_SIZE == front;}
    void enqueue(BinaryNode* e){
        if(isFull()){ error("THE QUEUE IS FULL"); }
        rear = (rear+1)%MAX_QUEUE_SIZE;
        data[rear] = e;
    }
    BinaryNode* dequeue(){
        if(isEmpty()){ error("THE QUEUE IS EMPTY"); }
        front = (front+1)%MAX_QUEUE_SIZE;
        return data[front];
    }
};