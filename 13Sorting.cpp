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
#include <cstdio>
#define MAX_ELEMENT 200

class HeapNode {
    int key;
public :
    HeapNode( int k=0 )
    : key(k){}
    void setKey(int k){ key = k; }
    int getKey(){ return key; }
    void display(){printf("%4d", key);}
};

class MaxHeap
{
    HeapNode node[MAX_ELEMENT];
    int size;
public:
    MaxHeap() : size(0) {}
    bool isEmpty() { return size == 0;}
    bool isFull() { return size == MAX_ELEMENT-1; }

    HeapNode& getParenrt(int i){ return node[i/2]; }
    HeapNode& getLeft(int i){ return node[i*2]; }
    HeapNode& getRight(int i ){ return node[i*2+1]; }

    void insert(int key){
        if( isFull() ) return;
        int i = ++size;

        while( i!=1 && key>getParenrt(i).getKey() ){
            node[i] = getParenrt(i);
            i /= 2;
        }
        node[i].setKey( key ); 
    }

    HeapNode remove(){
        if( isEmpty() ) { return NULL; }
        HeapNode item = node[1];
        HeapNode last = node[size--];
        int parent = 1;
        int child = 2;
        while(child <= size){
            if(child < size && (getLeft(parent).getKey() < getRight(parent).getKey())){
                child++;
            }
            if( last.getKey() >= node[child].getKey() ) break;

            node[parent] = node[child];
            parent = child;
            child *= 2;
        }
        node[parent] = last;
        return item;
     }
    HeapNode find() { return node[1]; }
    void display(){
        for(int i = 1, level = 1; i <= size; i++){
            if(i == level){
                printf("\n");
                level *= 2;
            }
            node[i].display();
        }
        printf("\n---------------------------------------------");
    }
};