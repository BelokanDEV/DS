#include "CircularQueue.h"

class CircularDeque : public CircularQueue{
    public :
    CircularDeque(){}
    ~CircularDeque(){}
    int deleteFront(){ return dequeue(); }
    int getFront(){ return peek(); }
    void addRear(int val){ enqueue(val); }

    int deleteRear(){
        if(isEmpty()) { error("THIS DEQUE IS EMPTY"); }
        else {
            int ret = data[rear];
            rear = (rear-1+MAX_QUEUE_SIZE)%MAX_QUEUE_SIZE; // (rear-1)%MAX_QUEUE_SIZE로 하지 않는이유 : 음수 방지 처리
            return ret;
        }
    }
    int getRear(){
        if(isFull()) { error("THIS DEQUE IS FULL"); }
        else { return data[rear]; }
    }
    void addFront(int val){
        if(isFull()) { error("THIS DEQUE IS FULL"); }
        else {
            data[front] = val;
            front = (front-1+MAX_QUEUE_SIZE)%MAX_QUEUE_SIZE;

        }
    }
         void display() {
            printf("Deque contents: ");
            int maxi = (front < rear) ? rear : rear+MAX_QUEUE_SIZE;
            for(int i = front+1 ; i<=maxi ; i++){
            printf("[%2d] ", data[i%MAX_QUEUE_SIZE]);
            }
            printf("\n");
        }
};