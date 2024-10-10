#include <cstdio>
#include <cstdlib>
class Node{ //2차원 행렬의 좌표를 데이터로 갖는 노드
    Node* link;
    int row;
    int col;
public :
    Node(int r = 0, int c = 0)
    : row(r), col(c), link(nullptr) {}
    ~Node(){}
    
    void setLoc(int r, int c){
        row = r;
        col = c;
    }
    void getLoc(int& r, int& c){
       r = row;
       c = col;
    }
    bool isNeighbor(Node &p){
        return (((row == p.row)&&((col == p.col-1)||(col == p.col+1))) || ((col == p.col)&&(row == p.row-1)||(row == p.row+1)));
    }
    bool operator==(Node &p){
        return((row == p.row)&&(col == p.col));
    }
    Node* getLink(){ return link; }
    void setLink(Node* p){ link = p; }
    void display() { printf("<%d, %d >",row, col); }
};