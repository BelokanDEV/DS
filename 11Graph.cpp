#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAX_VTXS 256
#define MAX_QUEUE_SIZE 20
#define MAX_ELEMENT 200
#define INF 9999

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

    // SrchAMGraph 내용
    void resetVisited() {
        for(int i = 0; i<size; i++)
            visited[i] = false;
    }
    bool isLinked(int u, int v) { return getEdge(u, v) != 0;}

    void DFS(int v){
        visited[v] = true;
        for(int w = 0; w<size; w++){
            if(isLinked(v,w) && visited[w] == false){ 
                DFS(w); 
            }
        }
    }
    void BFS(int v){
        visited[v] = true;
        printf("%c ", getVertex(v));

        CircularQueue que;
        que.enqueue(v);

        while(!que.isEmpty()){
            int v = que.dequeue();
            for(int w = 0; w<size; w++){
                if(isLinked(v,w)&&visited[w]==false){
                    visited[w] = true;
                    printf("%c ", getVertex(w));
                    que.enqueue(w);
                }
            }
        }
    }


    //PLPJ 내용
    //11-1
    void randomGraph(int numVtx, int numEdge) {
        reset(); // 기존 그래프 초기화
        for (int i = 0; i < numVtx; i++) {
            insertVertex('A' + i); // 정점 추가
        }

        int edgeCount = 0;
        while (edgeCount < numEdge) {
            int u = rand() % numVtx;
            int v = rand() % numVtx;

            if (u != v && getEdge(u, v) == 0) { // 자기 자신으로의 간선 및 중복 간선 방지
                insertEdge2(u, v); // 양방향 간선 삽입
                edgeCount++;
            }
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

	printf("(11.1-1) randomGraph()\n");
	g.randomGraph(6, 4);
	g.display(stdout);

    // printf("\n[12.(1)] Random Weighted Graph\n");
	// g.randomFullWGraph(7, 99);
	// g.display();

	// g.randomFullWGraph(5, 99);
	// g.display();

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