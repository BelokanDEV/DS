#include <iostream>

int transpose(int A[][2], int AT[][3])
{
    for(int j = 0 ; j<2; j++){
        for(int i = 0; i<3; i++){
            AT[j][i] = A[i][j];
        }
    }
}
int main (void)
{
    using namespace std;
    int A[2][3] = { {2, 3, 4},
                    {7, 8, 9} };
    return 0;
}