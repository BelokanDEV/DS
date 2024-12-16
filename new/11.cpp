#include <cstdio>
#include <cstdlib>
#include <ctime>
#define MAX_VTXS 256
#define INF 9999
#define MAX_QUEUE_SIZE 20

class AdjMatGraph{
    int size;
    char vertices[MAX_VTXS];
    int adj[MAX_VTXS][MAX_VTXS];
    bool visited[MAX_VTXS];
public :
    AdjMatGraph(){ reset(); }
    char getVertex(int i){return vertices[i];}
    int getEdge(int i, int j){return adj[i][j]; }
    void setEdge(int i, int j, int val){ adj[i][j] = val; }
    bool hasEdge(int i, int j){ return (getEdge(i,j)<INF); }

    bool isEmpty() { return size == 0; }
    bool isFull() { return size >= MAX_VTXS; }

    void reset(){
        size = 0;
        for(int i = 0; i<MAX_VTXS; i++)
        for(int j = 0; j<MAX_VTXS; j++){
            setEdge(i,j,0);
        }
    }
    void insertVertex(char name){
        if(!isFull()) vertices[size++] = name;
        else printf("ERROR!");
    }
    void insertEdge(int u, int v, int weight){
        setEdge(u,v,weight);
        setEdge(v,u,weight);
    }
    void display(FILE *fp = stdout){
        fprintf(fp, "%d\n", size);
        for(int i = 0; i < size; i++){
            fprintf(fp, "%c ", getVertex(i));
            for(int j = 0; j<size; j++){
                fprintf(fp, "%d ", getEdge(i,j));
            }
            fprintf(fp, "\n");
        }
    }
    void load(char* filename){
        FILE* fp = fopen(filename, "r");
        if(fp!=nullptr){
            int n, val;
            fscanf(fp, "%d", &n);
            for(int i = 0; i<n; i++){
                char str[80];
                fscanf(fp, "%s", str);
                insertVertex( str[0] );
                for(int j = 0; i<n; j++){
                    fscanf(fp, "%d", &val);
                    if(val!=0) insertEdge(i,j,1);
                }
            }
            fclose(fp);
        }
    }
    void store(char* filename){
        FILE *fp = fopen(filename, "w");
        if(fp!=nullptr){
            display(fp);
            fclose(fp);
        }
    }
    void randomGraph(int numVtx, int numEdge){
        reset();
        for(int i = 0; i<numVtx; i++){
            insertVertex('A' + i);
        }
        int edgeCount = 0;
        while(edgeCount<numEdge){
            int u = rand() % numVtx;
            int v = rand() % numVtx;

            if(u!=v && getEdge(u,v)==0){
                insertEdge(u,v,1);
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