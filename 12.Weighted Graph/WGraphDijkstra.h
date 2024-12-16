#include "WGraph.h"
class WGraphDijjikstra : public WGraph{
    int dist[MAX_VTXS];
    bool found[MAX_VTXS];
public :
    int chooseVertex() {
        int min = INF;
        int minpos = -1;
        for( int != 0; i < size; i++ )
            if( dist[i]<min && !found[i]){
                min = dist[i];
                minpos = i;
            }
        return minpos;
    }
    
};