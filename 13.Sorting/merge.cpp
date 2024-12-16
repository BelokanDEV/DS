#define MAX_SIZE 1024

#include <cstdio>
#include <cstdlib>
static void merge(int A[], int left, int mid, int right){
    int i, j, k = left, l;
    static int sorted[MAX_SIZE];
    for(i=left, j=mid+1; i<=mid && j<=right ;){
        sorted[k++] = (A[i]<=A[j]) ? A[i++] : A[j++];
    }
    if(i>mid)
        for( l=j ; l<=right ; l++, k++)
            sorted[k] = A[l];
    else
        for(l=i ; l<=mid ; l++, k++)
            sorted[k] = A[l];
    for(l=left ; l<=right; l++)
        A[l] = sorted[l];
}
void mergeSort(int A[], int left, int right){
    if(left<right){
        int mid = (left+right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid+1, right);
        merge(A, left, mid, right);
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
    mergeSort(list, 0, n-1);
    printArray(list, n, "Selection ");
    return 0;
}