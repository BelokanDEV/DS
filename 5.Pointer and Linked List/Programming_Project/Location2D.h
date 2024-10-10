#include <cstdio>
#include <cstdlib>

class Location2D{
    int row;
    int col;
    Location2D* link;
public : 
    Location2D(int r = 0, int c = 0)
    : row(r), col(c), link(nullptr){}
    ~Location2D(){}
    void setLoc(int r, int c){
        row = r;
        col = c;
    }
    int getRow() { return row; }
    int getCol() { return col; }
    Location2D* getLink() { return link; }
    void setLink (Location2D* p) { link = p; }
    void display() { printf("<%d, %d >",row, col); }
};