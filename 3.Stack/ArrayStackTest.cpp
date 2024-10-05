#include "ArrayStack.h"
#include <cstdio>

int main (void){
    ArrayStack a, b;

    a.push(1);
    a.push(5);
    a.push(5);
    a.push(7);
    a.push(8);
    b.push(a.pop());
    b.push(8);
    a.push(4);
    b.push(a.pop());
    b.push(8);

    a.display();
    b.display();
    
    return 0;
}