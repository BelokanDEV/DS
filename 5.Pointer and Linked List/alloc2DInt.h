int** alloc2Dint (int rows, int cols){

    if(rows <= 0 || cols <= 0) { return NULL; }
    int** mat = new int*[rows];
    for(int i = 0; i<rows; i++){
        mat[i] = new int[cols]
    }
    return mat;
}