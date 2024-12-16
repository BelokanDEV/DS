#include <cstdio>
#include <cstdlib>

static void sortGapsertion(int A[], int first, int last, int gap){
    int i, j, key;
    for(i = first + gap ; i <= last ; i= i+gap){
        key = A[i];
        for(j=i-gap ; j>= first && key<A[j] ; j = j-gap)
            A[j+gap] = A[j];
        A[j+gap] = key;
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
void shellSort (int A[], int n){
    for (int gap = n/2; gap>0; gap = gap/2){
        printArray(A,n,"Shell....");
        if((gap%2)==0)gap++;
        for(int i = 0; i<gap; i++){
            sortGapsertion(A, i, n-1, gap);
        }
    }
}


int main(){
    int list[16];
    int n = 16;
    initRandom(list,n);
    printArray(list,n,"Original ");
    shellSort(list, n);
    printArray(list, n, "Shell Sorting ");
    return 0;
}