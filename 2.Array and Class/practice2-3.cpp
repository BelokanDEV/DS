#include <cstdio>
int main (void){
    //Practice 2-3. PAGE 83
    int two[10];
    for(int i = 0; i<=9; i++){ two[i] = 1; }
    for(int i = 0; i<=9; i++){
        for(int j = 1; j<=i; j++){
            two[i] *= 2;
        }
    }
    for(int i = 0; i<=9; i++){
        printf("%d\n", two[i]);
    }
    return 0;
}