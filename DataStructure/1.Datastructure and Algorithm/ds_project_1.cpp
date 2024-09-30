/* 자료구조 P.49
* 1단원. 자료구조와 알고리즘 프로그래밍 프로젝트
* 프로젝트 1
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

#define num 80000

int sumAlgorithmA (int n);
int sumAlgorithmB (int n);
int sumAlgorithmC (int n);

int main (void)
{
    using namespace std;

    clock_t start, finish;
    double duration;

    start = clock();
    sumAlgorithmA(num);
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout <<"Algorithm A : " << duration << " " << "초입니다." << endl;
    // 알고리즘 A의 실행시간 분석

    start = clock();
    sumAlgorithmB(num);
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout <<"Algorithm B : " << duration << " " << "초입니다." << endl;
    // 알고리즘 B의 실행시간 분석

    start = clock();
    sumAlgorithmC(num);
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout <<"Algorithm C : " << duration << " " << "초입니다." << endl;
    // 알고리즘 C의 실행시간 분석

    return 0;
}

int sumAlgorithmA (int n)
{
    return (n * (n+1)) / 2;
}
int sumAlgorithmB (int n)
{
    int sum = 0;
    for(int i = 0; i<=n ; i++)
    {
        sum += i;
    }
    return sum;
}
int sumAlgorithmC(int n)
{
    int sum = 0;
    for(int i = 0; i<=n ; i++)
    {
        for(int j = 1; j<=i; j++)
        {
            sum += 1;
        }
    }
    return sum;
 }
