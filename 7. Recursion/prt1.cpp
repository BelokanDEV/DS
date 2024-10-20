#include <iostream>
int recursive(int n){
    if(n==1) return 0;
    return n*recursive(n);
}
int sum (int n){
    printf("%d\n", n);
    if( n<1) return 0;
    else return ( n+sum(n-1) );
}
int main (void){
    using namespace std;

    cout << recursive(0) << endl;
    return 0;
}