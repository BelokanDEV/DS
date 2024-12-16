#include "WGraph.h"

int main(void){
    WGraph g;
    g.load("graph.txt");
    printf("가중치 그래프 (graph.txt)\n");
    g.display("graph.txt");
}