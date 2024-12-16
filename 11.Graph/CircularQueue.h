#include <cstdio>
#include <cstdlib>

const int MAX_QUEUE_SIZE = 20;

inline void error(char* str){
    printf("%s",str);
    exit(1);
}

class CircularQueue{
    protected :
    int front;
    int rear;
    int data[MAX_QUEUE_SIZE];
    public :
    CircularQueue(){ front = rear = 0; }
    ~CircularQueue(){}
    bool isFull() { return (rear+1)%MAX_QUEUE_SIZE == front; }
    bool isEmpty() { return front == rear; }

    void enqueue(int e){
        if(isFull()){ error("QUEUE IS FULL\n"); }
        else { 
            rear = (rear+1)%MAX_QUEUE_SIZE;
            data[rear] = e; 
            }
    }
    int dequeue(){ 
        if(isEmpty()){ error("QUEUE IS EMPTY\n"); }
        else {
            front = (front+1)%MAX_QUEUE_SIZE;
            return data[front];
        }
    }
    int peek(){
        if(isEmpty()){ error("QUEUE IS EMPTY\n"); }
        else {
            front = (front+1)%MAX_QUEUE_SIZE;
            return data[front];
         }
    }
     void display() {
            if (isEmpty()) { 
                printf("QUEUE IS EMPTY\n"); 
                return; 
            }
            printf("Queue contents: ");
            int maxi = (front < rear) ? rear : rear+MAX_QUEUE_SIZE;
            for(int i = front+1 ; i<=maxi ; i++){
            printf("[%2d] ", data[i%MAX_QUEUE_SIZE]);
            }
            printf("\n");
        }
};
