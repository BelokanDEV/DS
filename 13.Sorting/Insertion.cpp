#include <cstdio>
#include <cstdlib>
void insertionSort(int A[], int n)
{
    for(int i = 1; i<n; i++){
        int key = A[i];
        int j;
        for(j=i-1 ; j>=0 && A[j] > key ; j--)
            A[j+1] = A[j];
        A[j+1] = key;
    }
}
static void initRandom(int list[], int n, int max=100){
    for( int i = 0; i<n; i++){
        list[i] = rand()%max;
    }
}
static void printArray(int arr[], int n, char *str = "Array"){
    printf("%s = ", str);
    for(int i = 0; i<n; i++){
        printf("%3d", arr[i]);
    }
    printf("\n");
}

int main(){
    int list[16];
    int n = 16;
    initRandom(list,n);
    printArray(list,n,"Original ");
    insertionSort(list, n);
    printArray(list, n, "Selection ");
    return 0;
}