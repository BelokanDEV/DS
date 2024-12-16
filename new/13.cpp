#include <cstdio>
#include <cstdlib>
#include <memory.h>

//기본도구
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
//힙 노드, 최대 힙
#define MAX_ELEMENT 20
class HeapNode{
    int key;
public :
    HeapNode(int val = 0)
    : key(val) {}
    ~HeapNode(){}
    int getkey(){return key;}
    void setKey(int val){key = val;}
    void display(){printf("%4d",key);}
};
class MaxHeap{
    HeapNode node[MAX_ELEMENT];
    int size;
public :
    MaxHeap() : size(0) {}
    bool isEmpty() { return size == 0; }
    bool isFull() { return size == MAX_ELEMENT-1; }
    HeapNode& getParent(int i){return node[i/2];}
    HeapNode& getLeft(int i){return node[i*2];}
    HeapNode& getRight(int i){return node[i*2+1];}
    void insert(int key){
        if(isFull()) return;
        int i = ++size;
        
        while(i!=1 && key>getParent(i).getkey()){
            node[i] = getParent(i);
            i /= 2;
        }
        node[i].setKey(key);
    }
    HeapNode remove(){
        if(isEmpty()) return NULL;
        HeapNode item = node[1];
        HeapNode last = node[size--];
        int parent = 1;
        int child = 2;
        while(child<=size){
            if(child<size && (getLeft(parent).getkey()<getRight(parent).getkey())){
                child++;
            }
            if(last.getkey()>node[child].getkey()) break;

            node[parent] = node[child];
            parent = child;
            child *= 2;
        }
        node[parent] = last;
        return item;
    }
};
//1. 선택 정렬
inline void swap(int& x, int& y){
    int t = x;
    x = y;
    y= t;
}
void selectionSort(int A[], int n){
    for(int i = 0; i<n-1; i++){
        int least = i;
        for(int j = i+1; j<n; j++) {
            if(A[j]<A[least]) least = j;
        }
        swap(A[i],A[least]);
    }
}
// 2. 삽입 정렬
void insertionSort(int A[], int n){
    int i, j, key;
    for(i = 1; i<n; i++){
        key = A[i];
        for(j = i - 1; j >= 0 && A[j] > key ; j-- ){
            A[j+1] = A[j];
        }
        A[j+1] = key;
    }
}
// 3.버블 정렬
void bubbleSort(int A[], int n){
    for(int i = n-1; i>0; i--){
        for(int j = 0; j<i; j++){
            if(A[j]>A[j+1]) { swap(A[j], A[j+1]); }
        }
    }
}
// 4.쉘 정렬
static void sortGapsertion(int A[], int first, int last, int gap){
    int i, j, key;
    for (i = first + gap ; i <= last ; i = i + gap){
        key = A[i];
        for(j = i - gap ; j >= first && key < A[j] ; j = j - gap){
            A[j+gap] = A[j];
        }
        A[j+gap] = key;
    }
}
void shellSort(int A[], int n){
    for(int gap =  n/2; gap>0; gap= gap/2){
        printArray(A,n,"Shell....");
        if((gap%2)==0)gap++;
        for(int i = 0; i<gap; i++){
            sortGapsertion(A,i,n-1,gap);
        }
    }
}
// 5. 퀵 정렬
static int partition(int A[], int left, int right){
    int low = left+1;
    int high = right;
    int pivot = A[left];

    while (low <= high){
        while(low<=right&&A[low]<pivot){
            low++;
        }
        while(high>=left&&A[high]>pivot){
            high--;
        }
        if(low<high){
            swap(A[low],A[high]);
        }
    }
    swap(A[left],A[high]);
    return high;
}
void quickSort(int A[], int left, int right){
    int q;
    if(left<right){
        int q = partition(A, left, right);
        quickSort(A,left,q-1);
        quickSort(A,q+1,right);
    }
}
// 6. 합병 정렬
#define MAX_SIZE 1024
static void merge(int A[], int left, int mid, int right){
    int i, j, k = left, l;
    static int sorted[MAX_SIZE];
    for(i=left,j=mid+1; i<=mid&&j<=right;){
        sorted[k++] = (A[i]<=A[j]) ? A[i++] : A[j++];
    }
    if(i>mid)
        for( l=j; l<=right; l++ ,k++)
            sorted[k] = A[l];
    else
        for(l = i; l<=mid; l++,k++)
            sorted[k] = A[l];
    for(l=left ; l<=right; l++)
        A[l] = sorted[l];
}
void mergeSort(int A[], int left, int right){
    if(left<right){
        int mid = (left+right) /2;
        mergeSort(A, left, mid);
        mergeSort(A, mid+1, right);
        merge(A, left, mid, right);
    }
}
// 7. 기수 정렬
// 8. 힙 정렬
void heapSort(int A[], int n){
    int i;
    MaxHeap h;

    for(i = 0; i<n; i++){
        h.insert(A[i]);
    }
    for(i = n-1; i>=0; i--)
        A[i] = h.remove().getkey();
    }


int main(){
    int list[16];
    int n = 16;
    initRandom(list,n);
    printArray(list,n,"Original ");
    heapSort(list, n);
    printArray(list, n, "Heap Sorting ");
    return 0;
}