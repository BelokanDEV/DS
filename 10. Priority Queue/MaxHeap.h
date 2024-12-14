#include <cstdio>

#define MAX_ELEMENT 200

const void error(char* str){
    printf("%s",str);
    error(1);
}

class HeapNode
{
    int key;
public :
    HeapNode(int k=0)
    : key(k){}
    void setKey(int k){key =k;}
    int getKey(){return key;}
    void display(){printf("%4d",key);}
};

class MaxHeap
{
    HeapNode node[MAX_ELEMENT];
    int size;
public :
    MaxHeap() : size(0){}
    bool isEmpty(){return size == 0;}
    bool isFull(){return size == MAX_ELEMENT-1; }

    HeapNode& getParent(int i){return node[i/2]; }
    HeapNode& getLeft(int i){return node[i*2]; }
    HeapNode& getRight(int i){return node[i*2+1]; }

    void insert(int key){}
    HeapNode remove(){
        if(isEmpty()) error ();
        HeapNode item = node[i];
        HeapNode last = node[size--];
        int parent = 1;
        int child = 2;
        while(child<=size){
            if(child<size&&getLeft(parent).getKey() < getRight(parent).getKey())
                child++;
            if(last.getKey()>=node[child].getKey()) break;
            node[parent] = node[child];
            parent = child;
            child *= 2;
        }
        node[parent] = last;
        return item;

    }
    HeapNode find(){}
};