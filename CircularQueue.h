#include <cstdio>
#include <cstdlib>
#define MAX_QUEUE_SIZE 20

inline void error(char* str){
    printf("%s",str);
    error(1);
}
class CircularQueue{
    int data[MAX_QUEUE_SIZE];
    int front;
    int rear;
public :
    CircularQueue()
    : {front = rear = 0;}
    ~CircularQueue(){}
    bool isFull(){ return front == (rear+1) % MAX_QUEUE_SIZE; }
    bool isEmpty(){ return front == rear; }
    void enqueue(int val){
        if(isFull()){error("QUEUE IS FULL !");}
        rear = (rear+1)%MAX_QUEUE_SIZE;
        data[rear] = val;
    }
    int dequeue(){
        if(isEmpty()){error("QUEUE IS EMPTY!");}
        front = (front+1)%MAX_QUEUE_SIZE;
        return data[front];
    }
};