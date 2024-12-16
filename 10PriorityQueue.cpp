#include <cstdio>
#include <cstdlib>
#define MAXELEM 20
#define MAX_ELEMENT 100

class MaxPriorityQueue {
    int elem[MAX_ELEMENT];
    int size;
public :
    MaxPriorityQueue()
    : size(0) {}
    void insert(int val){
        elem[size++] = val;
    };
    int remove(){
        int i, max, imax;
        max = elem[0];
        imax = 0;
        for(i=1; i<size; i++){
            if(max<elem[i]){
                max = elem[i];
                imax = i;
            }
        }
        for (i = imax; i < size -1; i++)
            elem[i] = elem[i+1];
        size--;
        return max;
    };
    int find() {
        int i, max, imax;
        max = elem[0];
        imax = 0;
        for(i=1;i<size;i++){
            if(max<elem[i]){
                max = elem[i];
                imax = i;
            }
        }
        return max;
    };
    void display() {
        int i, max, imax;
        printf("PQueue(MAX) : ");
        for(i = 0; i< size ; i ++){
            printf("%3d ", elem[i]);
        }
        printf("\n");
    };
};

class Node {
public :
    int data;
    Node* link;
    Node(int val)
    : data(val){}

    int getKey() { return data; }
    void insertNext(Node* n){
        if(n!=nullptr){
            n->link = link;
            link = n;
        }
    }
    Node* removeNext() {
        Node* removed = link;
        if (removed != nullptr)
            link = removed->link;
        return removed;
    }
};

class LinkedList {
public:
    Node org;

    LinkedList()
    : org(0) {
        org.link = nullptr; // 명시적으로 초기화
    }
    ~LinkedList() {}
};
class MinPriorityQueue : public LinkedList {
public:
    void insert(int val){
    Node* prv = &(org);
    while (prv->link != nullptr && prv->link->data < val)
		prv = prv->link;
    prv->insertNext(new Node(val));
    }
    int remove() {
        Node*n = org.link;
        if(n==nullptr) return -1;

        org.link = n->link;
        int data = n->data;

        free(n);
        return data;
    }
    int find() {
        if(org.link != nullptr)
            return org.link->data;
        else return -1;
    }
    void display() {
        Node*n = org.link;
        printf("PQueue(Min): ");
        for(; n!=nullptr; n=n->link){
            printf("%3d", n->data);
        }
        printf("\n");
    }
};

int main(void){
    	int i, val, lMax[100], lMin[100];
	MaxPriorityQueue qMax;
	MinPriorityQueue qMin;


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
		val = qMin.remove();
		printf("%2d %2d\n", val, qMax.remove());

		lMin[i] = val;
		lMax[MAXELEM-i+1] = val;
	}
}
