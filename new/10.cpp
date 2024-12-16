#include <cstdio>
#include <cstdlib>
#define MAX_ELEM 20
#define MAXELEM 20

class MaxPriorityQueue{
    int elem[MAX_ELEM];
    int size;
public :
    MaxPriorityQueue()
    :size(0){}
    ~MaxPriorityQueue(){}
    void insert(int val){
        elem[size++] = val;
    }
    int remove(){
        int i, max, imax;
        max = elem[0];
        imax = 0;
        for(i = 0; i<size; i++){
            if(max<elem[i]){
                max = elem[i];
                imax = i;
            }
        }
        for(i = 0; i<size-1; i++){
            elem[i] = elem[i+1];
        }
    size--;
    return max;
    }
    int find(){
        int i, max, imax;
        max = elem[0];
        imax = 0;
        for(i = 0 ; i < size; i++){
            if(max<elem[i]){
                max = elem[i];
                imax = i;
            }
        }
        return max;
    }
    void display(){
        int i;
        printf("\nMaxPriorityQueue : ");
        for(i = 0; i< size; i++){
            printf("[%3d]", elem[i]);
        }
    }
};
class Node{
public :
    Node* link;
    int data;
public :
    Node(int val)
    : data(val){}
    int getData(){return data;}
    void insertNext(Node* n){
        if(n!=nullptr){
            n->link = link;
            link = n;
        }
    }
    Node* removeNext(){
        Node* removed = link;
        if(removed!=nullptr){
            link = removed->link;
        }
        return removed;
    }
};
class minPriorityQueue{
    Node org;
public :
    minPriorityQueue()
    : org(0) {}
    ~minPriorityQueue(){}
    void insert(int val){
        Node* prv = &(org);
        while(prv->link != nullptr && prv->link->data < val)
            prv = prv->link;
        prv->insertNext(new Node(val));
    }
    int removed(){
        Node* n = org.link;
        if(n==nullptr) return -1;

        org.link = n->link;
        int data = n->data;

        free(n);
        return data;
    }
    int find(){
        if(org.link != nullptr)
            return org.link->data;
        else return -1;
    }
    void display(){
        Node* n = org.link;
        for(;n!=nullptr;n=n->link)
            printf("%3d", n->data);
    }
};
    int isMaxHeapIter(int* list, int len){
        int i, iLeft, iRight;
        for(i = 1; i<len; i++){
            iLeft = i*2;
            iRight = i*2 + 1;

            if(iLeft <= len && list[iLeft] > list[i]) return 0;
            if(iLeft <= len && list[iRight] > list[i]) return 0;
        }
        return 1;
    };
    int isMinHeapIter(int* list, int len){
        int i, iLeft, iRight;
        for(i = 1; i<len; i++){
            iLeft = i*2;
            iRight = i*2+1;

            if(iLeft <= len && list[iLeft] < list[i]) return 0;
            if(iRight <= len && list[iRight] < list [i]) return 0;
        }
        return 1;
    };
int main(void){
    	int i, val, lMax[100], lMin[100];
	MaxPriorityQueue qMax;
	minPriorityQueue qMin;


	//========================================================
	printf("(1) MaxHeap (정렬되지 않은 배열)\n");
	printf("(2) MinHeap (정렬된 연결 리스트)\n");
	for (i = 0; i < MAXELEM; i++) {
		val = rand() % 100;
		qMax.insert(val);
		qMin.insert(val);
	}
	qMax.display();
	qMin.display();

	lMin[0] = lMax[0] = -1;
	for (i = 1; i <= MAXELEM; i++) {
		val = qMin.removed();
		printf("%2d %2d\n", val, qMax.remove());

		lMin[i] = val;
		lMax[MAXELEM-i+1] = val;
	}
    //========================================================
	printf("(3) 힙 속성 검사\n");
	printf(" MIN LIST: ");
	for (i = 0; i <= MAXELEM; i++)
		printf("%2d ", lMin[i]);
	printf("\n");

	val = isMinHeapIter(lMin, MAXELEM);
	printf(" 최소 힙인지 %s(반복)\n", (val == 0) ? "아님" : "맞음");
	val = isMaxHeapIter(lMin, MAXELEM);
	printf(" 최대 힙인지 %s(반복)\n", (val == 0) ? "아님" : "맞음");

	printf("\n MAX LIST: ");
	for (i = 0; i <= MAXELEM; i++)
		printf("%2d ", lMax[i]);
	printf("\n");

	val = isMinHeapIter(lMax, MAXELEM);
	printf(" 최소 힙인지 %s(반복)\n", (val == 0) ? "아님" : "맞음");
	val = isMaxHeapIter(lMax, MAXELEM);
	printf(" 최대 힙인지 %s(반복)\n", (val == 0) ? "아님" : "맞음");
}
