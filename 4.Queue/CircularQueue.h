#include <cstdio>
#include <cstdlib>

const int MAX_QUEUE_SIZE = 5;

inline void error(char* str){
    printf("%s",str);
    exit(1);
}

class CircularQueue{
    private :
    int front;
    int rear;
    int data[MAX_QUEUE_SIZE];
    public :
    CircularQueue(){ front = rear = 0; }
    ~CircularQueue(){}
    bool isFull() { return front%MAX_QUEUE_SIZE == (rear+1)%MAX_QUEUE_SIZE; }
    bool isEmpty() { return front%MAX_QUEUE_SIZE == rear%MAX_QUEUE_SIZE; }

    void enqueue(int e){
        if(isFull()){ error("QUEUE IS FULL\n"); }
        data[(++rear)%MAX_QUEUE_SIZE] = e; 
        }
    int dequeue(){ 
        if(isEmpty()){ error("QUEUE IS EMPTY\n"); }
        return data[(++front)%MAX_QUEUE_SIZE];
        }
    int peek(){
        if(isEmpty()){ error("QUEUE IS EMPTY\n"); }
        return data[(front+1)%MAX_QUEUE_SIZE];
    }
     void display() {
            if (isEmpty()) { 
                printf("QUEUE IS EMPTY\n"); 
                return; 
            }
            printf("Queue contents: ");
            for(int i = (front+1)%MAX_QUEUE_SIZE; i!= (rear+1)%MAX_QUEUE_SIZE; i = (i+1)%MAX_QUEUE_SIZE){
            printf("%d ", data[i]);
            }
            printf("\n");
        }
};
