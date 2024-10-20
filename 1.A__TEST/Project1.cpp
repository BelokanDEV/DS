#include <cstdio>
#include <iostream>
#include <ctime>

int A (int n){ return (n*(n+1))/2; }
int B (int n){
    int sum = 0;
    for(int i = 0; i<= n; i ++){
        sum += i;
    }
    return sum;
}
int C(int n){
    int sum = 0;
    for(int i = 0; i<=n; i++){
        for(int j = 1; j<=i; j++){
            sum += 1;
        }
    }
    return sum;
}

int main(void){
    using namespace std;
    cout << A(10) << endl;
    cout << B(10) << endl;
    cout << C(10) << endl;

}