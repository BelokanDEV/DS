#include <cstdio>
#include <cstdlib>

struct Customer{
    int id;         //고객 번호
    int tArrival;   //고객 도착 시간
    int tService;   //고객 서비스 소요 시간
    public :
    Customer(int i = 0, int tArr = 0 , int tServ = 0)
    : id(i), tArrival(tArr), tService(tServ){}
};