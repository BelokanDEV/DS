#include <cstdio>
#include <cstdlib>

int** alloc2Dint (int rows, int cols){
    if(rows <= 0 || cols <= 0) { return NULL; }
    int** mat = new int*[rows];
    for(int i = 0; i<rows; i++){
        mat[i] = new int[cols];
    }
    return mat;
}
void free2DInt(int** mat, int rows, int cols){
    if(mat != NULL){
    for(int i = 0; i<rows; i++)
        delete [] mat[i];
    delete [] mat;
    }
}
void set2DRandom(int** mat, int rows, int cols){
    for( int i = 0 ; i < rows ; i++ )
    for( int j = 0 ; j < cols ; j++ )
        mat[i][j] = rand()%100;
}

void print2DInt (int** mat, int rows, int cols){
    printf("행의 수 : %d, 열의 수 = %d\n", rows, cols);
    for (int i = 0; i<rows; i++){
        for(int j=0; j<cols; j++){ printf("%4d", mat[i][j]); }
    printf("\n");
    }
}

int main (void){
    int** mat;
    int rows, cols;

    printf(" 행과 열의 크기를 입력하세요 : ");
    scanf("%d%d", &rows, &cols);

    mat = alloc2Dint(rows, cols);
    set2DRandom(mat, rows, cols);
    print2DInt(mat, rows, cols);
    free2DInt(mat, rows, cols);

    return 0;
}