#include<cstdio>
#include <cstdlib>
#include <ctime>

#define MAX_VTXS 256
#define MAX_QUEUE_SIZE 20
#define MAX_ELEMENT 200
#define INF 9999
#define MAX_ELEMENT 200
#define MAX_VERTICES 1024
class HeapNode{
    int key;
    int v1;
    int v2;
public :
    HeapNode(int k = 0, int u = 0, int v =0)
    : key(k), v1(u), v2(v) {}
    ~HeapNode(void){}
    void set (int k, int u, int v){
        key = k;
        v1 = u;
        v2 = v;
    }
    void setKey(int k) { key = k; }
    int getKey() { return key; }
    int getV1() { return v1; }
    int getV2() { return v2; }
    void display() { printf("\t(%2d-%2d) -- %d\n", v1, v2, key); }
};

class MinHeap
{
    HeapNode node[MAX_ELEMENT];
    int size;
public :
    MinHeap() : size(0) {}
    bool isEmpty() { return size == 0; }
    bool isFull() { return size == MAX_ELEMENT -1; }

    HeapNode& getParent(int i){ return node[i/2]; }
    HeapNode& getLeft(int i){ return node[i*2]; }
    HeapNode& getRight(int i){ return node[i*2+1]; }

    void insert(int key, int u, int v) {
        if( isFull() ) return;

        int i = ++size;

        while ( i != 1 && key<getParent(i).getKey()){
            node[i] = getParent(i);
            i /= 2;
        }
        node[i].set(key, u, v);
    }
    HeapNode remove() {
        if(isEmpty()) return NULL;

        HeapNode root = node[1];
        HeapNode last = node[size--];

        int parent = 1;
        int child = 2;

        while (child <= size){
            if(child<size && getLeft(parent).getKey() > getRight(parent).getKey())
                child++;
            if(last.getKey() <= node[child].getKey()) break;
            node[parent] = node[child];
            parent = child;
            child *= 2;
        }
        node[parent] = last;
        return root;
    }
};
class VertexSets{
    int parent[MAX_VERTICES];
    int size;
public :
    VertexSets(int nSets){
        size =nSets;
        for (int i = 0; i<nSets; i++)
            parent[i] = -1;
    }
    bool isRoot(int i){return parent[i]<0; }
    int findSet(int vertex){
        int id = vertex;
        while(!sRoot(id)) id = parent[id];
        return id;
    }
    void unionSets(int s1, int s2){
        parent[s1] = s2;
        size--;
    }
};


inline void error(char* str){
    printf("%s",str);
    exit(1);
}
class CircularQueue{
    int data[MAX_QUEUE_SIZE];
    int front;
    int rear;
public :
    CircularQueue() {front = rear = 0;}
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

class AdjMatGraph{
protected :
    int size;
    char vertices[MAX_VTXS];
    int adj[MAX_VTXS][MAX_VTXS];
    bool visited[MAX_VTXS];
    
public :
    AdjMatGraph(){ reset(); }
    char getVertex(int i) { return vertices[i]; }
    int getEdge(int i, int j) { return adj[i][j]; }
    void setEdge(int i, int j, int val) { adj[i][j] = val; }
    bool hasEdge(int i, int j){ return (getEdge(i, j)<INF); }

    bool isEmpty() { return size == 0; }
    bool isFull() { return size>= MAX_VTXS; }

    void reset() {
        size = 0;
        for(int i = 0; i<MAX_VTXS; i++)
        for(int j = 0; j<MAX_VTXS; j++){
            setEdge(i,j,0);
        }
    }

    void insertVertex( char name ){
        if(!isFull()) vertices[size++] = name;
        else printf("Error : 그래프 정점 개수 초과\n");
    }

    void insertEdge(int u, int v, int weight){
        setEdge(u,v,weight);
        setEdge(v,u,weight);
    }
    void insertEdge(int u, int v){
        setEdge(u,v,1);
    }
    void insertEdge2(int u, int v){
        setEdge(u,v,1);
        setEdge(v,u,1);
    }

    void display( FILE *fp = stdout) {
        fprintf(fp, "%d\n", size);
        for(int i = 0; i < size ; i++){
            fprintf(fp,"%c  ", getVertex(i));
            for(int j = 0; j<size; j++){
                fprintf(fp, " %3d", getEdge(i,j));
            }
            fprintf(fp,"\n");
        }
    }
    void load(char* filename){
        FILE *fp = fopen(filename, "r");
        if(fp != nullptr){
            int n;
            fscanf(fp, "%d", &n);
            for(int i = 0; i<n; i++){
                char str[80];
                fscanf(fp, "%s", str);
                insertVertex( str[0]  );
                for(int j = 0; j<n; j++){
                    int val;
                    fscanf(fp, "%d", &val);
                    if(val != 0)
                        insertEdge(i,j);
                }
            }
            fclose(fp);
        }
    }
    void store(char* filename){
        FILE *fp = fopen(filename, "w");
        if(fp != nullptr){
            display(fp);
            fclose(fp);
        }
    }

    //12-1
  	void randomFullWGraph(int nVtx, int maxW=1000) {
		int i, j, n, r, c;

		reset();
		for (i = 0; i < nVtx; i++) {
			insertVertex('A' + i);
			adj[i][i] = 0;
		}
		// fully connected graph
		for (i = 0; i<nVtx; i++)
			for (j = 0; j < i; j++)
				insertEdge(i, j, (rand() % maxW + 1));
	}
};
   


int main(void){
    int n;
	AdjMatGraph g;
	srand((unsigned int)time(NULL));

    printf("\n[12.(1)] Random Weighted Graph\n");
	g.randomFullWGraph(7, 99);
	g.display();

	g.randomFullWGraph(5, 99);
	g.display();

	// printf("\n[12.(2)] MST :  Kruskal         Prim\n");

	// for (n = 5 ; n < 100 ; n += 5) {
	// 	printf("%-3d\t", n);
	// 	srchMSTAvgTime(&g, n, 20);
	// }

	// printf("\n[12.(3)] SP :   Dijkstra        Floyd\n");
	// for (n = 5; n < 100; n += 5) {
	// 	printf("%-3d\t", n);
	// 	srchSPAvgTime(&g, n, 20);
	// }
    return 0;
}