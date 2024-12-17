#include <cstdio>
#include <cstdlib>
#include <ctime>

#define INF 999
#define MAX_VTXS 256

class AdjMatGraph{
    int size;
    char vertices[MAX_VTXS];
    int Adj[MAX_VTXS][MAX_VTXS];
    bool visited[MAX_VTXS];
public :
    AdjMatGraph()
    : size(0) {}
    ~AdjMatGraph(){reset();}
    char getVertex(int i){ return vertices[i]; }
    int getEdge(int i, int j){ return Adj[i][j]; }
    void setEdge(int i, int j, int val) { Adj[i][j] = val; }
    bool hasEdge(int i, int j){ return Adj[i][j] < INF; }
    bool isFull() {return size>=MAX_VTXS; }
    bool isEmpty() {return size == 0; }
    void reset(){
        for(int i = 0; i<size; i++)
        for(int j = 0; j<size; j++)
            setEdge(i,j,0);
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
            for(int j = 0; j < size ;j++){
                fprintf(fp, "%d ", getEdge(i,j));
            }
            fprintf(fp,"\n");
        }
    }
    void load(char* filename){
        FILE* fp = fopen(filename, "r");
        while(fp!=nullptr){
            int n, val;
            fscanf(fp,"%d",&n);
            for(int i = 0; i<n; i++){
                char str[80];
                fscanf(fp, "%s", str);
                insertVertex(str[0]);
                for(int j = 0; j<n; j++){
                    fscanf(fp, "%d", &val);
                    insertEdge(i,j,val);
                }
            }
            fclose(fp);
        }
    }
    void store(char* filename){
        FILE* fp = fopen(filename, "w");
        if(fp!=nullptr){
            display(fp);
            fclose(fp);
        }
    }
    void randomGraph(int numVtx, int numEdge){
        reset();
        for(int i = 0; i<numVtx; i++){
            insertVertex('A'+i);
        }
        int edgeCount = 0;
        while(edgeCount < numEdge){
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
	AdjMatGraph g;
	srand((unsigned int)time(NULL));

	printf("(11.1-1) randomGraph()\n");
	g.randomGraph(6, 4);
	g.display(stdout);
    return 0;
}