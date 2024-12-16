#include "AdjMatGraph.h"
int main(){
    AdjMatGraph g;

    for(int i = 0; i<8; i++){
        g.insertVertex('A'+i);
    }
    g.insertEdge(0,1);
    g.insertEdge(0,2);

    g.insertEdge(1,0);
    g.insertEdge(1,3);

    g.insertEdge(2,0);
    g.insertEdge(2,3);
    g.insertEdge(2,4);

    g.insertEdge(3,1);
    g.insertEdge(3,2);
    g.insertEdge(3,5);

    g.insertEdge(4,2);
    g.insertEdge(4,6);
    g.insertEdge(4,7);

    g.insertEdge(5,3);

    g.insertEdge(6,4);
    g.insertEdge(6,7);

    g.insertEdge(7,4);
    g.insertEdge(7,6);

    printf("인접 행렬로 표현한 그래프\n");
    g.display();
    g.store("graph.txt");

    g.reset();
    g.load("graph.txt");
    printf("인접 행렬로 표현한 그래프 (파일 : graph.txt)\n");
    g.display();
    return 0;
}