#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAX_VTXS 256
#define MAX_QUEUE_SIZE 20
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
        else printf("Error\n");
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
    void load(char *filename) {
            FILE *fp = fopen(filename, "r");
            if (fp != NULL) {
                int n, val;
                fscanf(fp, "%d", &n);
                for (int i = 0; i<n; i++) {
                    char	str[80];
                    int		val;
                    fscanf(fp, "%s", str);
                    insertVertex(str[0]);
                    for (int j = 0; j<n; j++) {
                        fscanf(fp, "%d", &val);
                        if (val != 0)
                            insertEdge(i, j);
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

    // SrchAMGraph
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


    //PLPJ 
    //11-1
    void randomGraph(int numVtx, int numEdge) {
        reset(); 
        for (int i = 0; i < numVtx; i++) {
            insertVertex('A' + i); 
        }

        int edgeCount = 0;
        while (edgeCount < numEdge) {
            int u = rand() % numVtx;
            int v = rand() % numVtx;

            if (u != v && getEdge(u, v) == 0) { 
                insertEdge2(u, v); 
                edgeCount++;
            }
        }
    }
    
};
int main(void){
    int n;
	AdjMatGraph g;
	srand((unsigned int)time(NULL));

	printf("(11.1-1) randomGraph()\n");
	g.randomGraph(6, 4);
	g.display(stdout);
    return 0;
}