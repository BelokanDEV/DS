#include "SrchAMGraph.h"

int main(void){
    SrchAMGraph g;
    g.load("graph.txt");
    printf("그래프(graph.txt)\n");
    g.display();

    printf("DFS ==> ");
    g.resetVisted();
    g.DFS(0);
    printf("\n");

    printf("BFS ==> ");
    g.resetVisted();
    g.BFS(0);
    printf("\n");
}