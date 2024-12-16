#include <cstdio>
#include <cstdlib>

inline void swap(int& x, int& y){
    int t =x;
    x = y;
    y = t;
}

void bubbleSort(int A[], int n){
    for(int i=n-1; i>0; i--){
        for(int j = 0; j<i; j++)
            if(A[j]>A[j+1]) { swap(A[j],A[j+1]); }
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
    bubbleSort(list, n);
    printArray(list, n, "bubble");
    return 0;
}