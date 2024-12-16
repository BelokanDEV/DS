#include <cstdio>
#include <cstdlib>
#define MAX_QUEUE_SIZE 20
#define MAX_ELEMENT 200
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
#include <memory.h>
#include "SortAlgorithms.h"

void initRandom(int list[], int n) {
	int i;
	for (i = 0; i<n; i++)
		list[i] = rand();
		//list[i] = rand() * rand();
}
void initAscend(int list[], int n) {
	int i;
	for (i = 0; i<n; i++)
		list[i] = i;
}
void initDescend(int list[], int n) {
	int i;
	for (i = 0; i<n; i++)
		list[i] = n-i;
}

void printArray(int arr[], int n, char *str)
{
	int i;
	printf("%s = ", str);
	for (i = 0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void copyArray(int src[], int dst[], int n) {
	memcpy(dst, src, n*sizeof(int));
}


//====================================================================
// 1. Insertion Sort
//====================================================================
void insertionSort(int list[], int n)
{
	int i, j, key;
	for (i = 1; i<n; i++){
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--)
			list[j + 1] = list[j];
		list[j + 1] = key;
		//printStep(list, n, i);
	}
}


//====================================================================
// 2. Selection Sort
//====================================================================
static void swap(int* x, int* y) {
	int	t = *x;
	*x = *y;
	*y = t;
}
//====================================================================
// 3. Bubble Sort
//====================================================================
void bubbleSort(int list[], int n)
{
	int i, j, bChanged = 1;
	for (i = n - 1; i>0; i--){
		bChanged = 0;
		for (j = 0; j<i; j++)
		if (list[j]>list[j + 1]) {
			swap(&list[j], &list[j + 1]);
			bChanged = 1;
		}
		if (!bChanged) break;
		//printStep(list, n, n - i);
	}
}

//====================================================================
// 4. Shell Sort
//====================================================================
static void sortIncInsertion(int list[], int first, int last, int gap)
{
	int i, j, key;
	for (i = first + gap; i <= last; i = i + gap){
		key = list[i];
		for (j = i - gap; j >= first && key<list[j]; j = j - gap)
			list[j + gap] = list[j];
		list[j + gap] = key;
	}
}

void shellSort(int list[], int n)
{
	int i, gap, count = 1;
	for (gap = n / 2; gap>0; gap = gap / 2) {
		if ((gap % 2) == 0) gap++;
		for (i = 0; i<gap; i++)
			sortIncInsertion(list, i, n - 1, gap);
		//printStep(list, n, count++);

	}
}

//====================================================================
// 5. Merge Sort
//====================================================================
static int *sorted = NULL;
static void Merge(int list[], int left, int mid, int right)
{
	int i, j, k = left, l;
	if ( sorted == NULL )
		sorted = (int*)malloc(sizeof(int)*MAX_NUM);

	for (i = left, j = mid + 1; i <= mid && j <= right;)
		sorted[k++] = (list[i] <= list[j])
		? list[i++]
		: list[j++];

	if (i > mid)
	for (l = j; l <= right; l++, k++)
		sorted[k] = list[l];
	else
	for (l = i; l <= mid; l++, k++)
		sorted[k] = list[l];

	for (l = left; l <= right; l++)
		list[l] = sorted[l];
}
void mergeSort(int list[], int left, int right)
{
	int mid;
	if (left<right) {
		mid = (left + right) / 2;
		mergeSort(list, left, mid);
		mergeSort(list, mid + 1, right);
		Merge(list, left, mid, right);
	}
}

//====================================================================
//6.  Heap Sort
//====================================================================
#include "MaxHeap.h"
void heapSort(int a[], int n)
{
	int i;
	MaxHeap h;

	for (i = 0; i<n; i++)
		h.insert(a[i]);

	for (i = n - 1; i >= 0; i--)
		a[i] = h.remove().key;
}

//====================================================================
//7. Radix Sort
//====================================================================
#include "CircularQueue.h"
#define BUCKETS 10
#define DIGITS  4
void radixSort(int list[], int n)
{
	int i, b, d, factor = 1;
	CircularQueue queues[BUCKETS];
	//for (i = 0; i<BUCKETS; i++)
	//	initQueue(&queues[i]);

	for (d = 0; d<DIGITS; d++){
		for (i = 0; i<n; i++)
			queues[(list[i] / factor) % 10].enqueue(list[i]);

		for (b = i = 0; b<BUCKETS; b++)
		while (!queues[b].isEmpty())
			list[i++] = queues[b].dequeue();
		factor *= 10;
	}
}


//====================================================================
//8. Quick Sort
//====================================================================
static int partition(int list[], int left, int right)
{
	int low = left;
	int high = right + 1;
	int pivot = list[left];
	do {
		do {
			low++;
		} while (low <= right &&list[low]<pivot);

		do {
			high--;
		} while (high >= left && list[high]>pivot);

		if (low<high)
			swap(&list[low], &list[high]);
	} while (low<high);

	swap(&list[left], &list[high]);
	return high;
}

void quickSort(int list[], int left, int right)
{
	int q;
	if (left<right){
		if (left == 1500) {
			q=1;
		}
		q = partition(list, left, right);
		quickSort(list, left, q - 1);
		quickSort(list, q + 1, right);
	}
}

/* A[] --> Array to be sorted,
l  --> Starting index,
h  --> Ending index */
// Create an auxiliary stack
static int stack[MAX_NUM];
void quickSort2(int arr[], int l, int h)
{
	int p;
	// initialize top of stack
	int top = -1;

	// push initial values of l and h to stack
	stack[++top] = l;
	stack[++top] = h;

	// Keep popping from stack while is not empty
	while (top >= 0)
	{
		// Pop h and l
		h = stack[top--];
		l = stack[top--];

		// Set pivot element at its correct position
		// in sorted array
		p = partition(arr, l, h);

		// If there are elements on left side of pivot,
		// then push left side to stack
		if (p - 1 > l) {
			stack[++top] = l;
			stack[++top] = p - 1;
		}

		// If there are elements on right side of pivot,
		// then push right side to stack
		if (p + 1 < h) {
			stack[++top] = p + 1;
			stack[++top] = h;
		}
	}
}