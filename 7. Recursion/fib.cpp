#include <cstdio>
#include <iostream>

int fib(int n){
    if(n<2) return n;
    return (fib(n-1) + fib(n-2));
}

int fibIter(int n){
    if(n<2){return n;}
    else{
        int tmp, current = 1, last = 0;
        for (int i = 2 ; i<=n; i++){
            temp = current;
            current += last;
            last = temp;
        }
        return current;
    }

}


int main (void){
    using namespace std;
    cout << fibIter(10) << endl;
    
    return 0;
}