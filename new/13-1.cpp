#include <cstdio>
#include <cstdlib>
#include <memory.h>

static void initRandom(int A[], int n, int max=100){
    for(int i = 0; i<n; i++){
        A[i] = rand() % max;
    }
}
static void printArray(int A[], int n, char* str ="Array"){
    printf("%s = ", str);
    for(int i =0; i<n; i++){
        printf("%3d", A[i]);
    }
    printf("\n");
}

#define MAX_ELEM 20
class HeapNode{
    int key;
public :
    HeapNode(int val = 0)
    : key(val){}
    ~HeapNode(){}
    int getkey(){return key;}
    void setkey(int val){key = val;}
    void display(){printf("%4d",key);}
};
class MaxHeap{
    HeapNode node[MAX_ELEM];
    int size;
public :
    MaxHeap()
    : size(0) {}
    ~MaxHeap(){}
    bool isFull() {return size == MAX_ELEM - 1;}
    bool isEmpty() { return size == 0; }
    HeapNode& getParent(int i) { return node[i/2]; }
    HeapNode& getLeft(int i) { return node[i*2]; }
    HeapNode& getRight(int i) { return node[i*2+1]; }
    
    void insert(int key){
        if(isFull()) return;
        int i = ++size;

        while(i != 1 && key > getParent(i).getkey()){
            node[i] = getParent(i);
            i /= 2;
        }
        node[i].setkey(key);
    }
    HeapNode* remove(){
        if(isEmpty()) return NULL;
        HeapNode item = node[1];
        HeapNode last = node[size--];
        int parent = 1;
        int child = 2;
        while(child<=size){
            if(child<size && getLeft(parent).getKey()< getRight(parent).getKey())
                child++;
            if(last.getkey() > node[child].getkey()) break;

            node[parent] = node[child];
            parent = child;
            child *= 2;
        }
        node[parent] = last;
        return item;
    }
};
inline void swap(int& x, int& y){
    int t = x;
    x = y;
    y = t;
}
void selectionSort(int A[], int n){
    for(int i = 0; i<n-1; i++){ 
    int least = i;
    for(int j = i+1; j<n; j++){
        if(A[j]<A[least]) least = j;
    }
    swap(A[i], A[least]);
    }
}

int main(void){}