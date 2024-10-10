struct Node {
    int row;
    int col;

    Node(int r = 0, int c = 0){
        row = r;
        col = c;
    }
    bool isNeighbor(Node &p){
        return (((row == p.row)&&((col == p.col-1)||(col == p.col+1))) || ((col == p.col)&&(row == p.row-1)||(row == p.row+1)));
    }
    bool operator==(Node &p){
        return((row == p.row)&&(col == p.col));
    }
};