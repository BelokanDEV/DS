#include <cstdio>
#include <cstdlib>

inline void swap(int& x, int& y){
    int t =x;
    x = y;
    y = t;
}

void selectionSort(int A[], int n){
    for(int i = 0; i<n-1; i++){
        int least = i;
        for(int j = i+1; j<n ; j++){
            if(A[j]<A[least]) least = j;
        }
            swap(A[i], A[least]);
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
    selectionSort(list, n);
    printArray(list, n, "Selection ");
    return 0;
}