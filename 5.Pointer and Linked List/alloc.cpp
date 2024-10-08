#include <cstdio>

int main(void){
    char* str = new char[1000];
    if(str == NULL){
        printf("Insufficient memory available\n");
    }
    else {
        printf("Allocated 1000 bytes\n");
        delete [] str;
        printf("Memory freed\n");
    }
    delete [] str;
}
