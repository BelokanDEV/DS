#include <cstdio>
#include <cstdlib>
#include <time.h>

#define MAX_QUEUE_SIZE 100
inline void error(char* str){
    printf("%s", str);
    exit(1);
}

struct Customer{
    int id;
    int tArrival;
    int tService;
    Customer(int i, int tArr, int tSer)
    : id(i), tArrival(tArr), tService(tSer){}
}

class CustomerQueue{
    Customer data[MAX_QUEUE_SIZE];
    int front;
    int rear;
public :
    bool isEmpty(){ front == rear; }
    void isFull(){ front == (rear+1)%MAX_QUEUE_SIZE; }
    void enqueue(Customer n){
        if( isFull( )) { error("STACK IS FULL"); }
        rear = (rear+1)%MAX_QUEUE_SIZE;
        data[rear] = n;
    }
    Customer dequeue(){
        if( isEmpty( )) { error("STACK IS EMPTY")}
        Customer temp = data[front];
        front = (front+1)%MAX_QUEUE_SIZE;
        return temp;
    }
}
class BankSimulator{
    int nSimulation;
    double probArrival;
    int tMaxService;

    int totalWaitTime;
    int nServedCustomers;
    int nCustomers;
    CustomerQueue que;

    double Random(){ rand()/(double)RAND_MAX; }
    bool isNewCustomer() { probArrival>random(); }
    int randServicetime() {return (int)(Random()*tMaxService)+1; }
    void insertCustomers(int arrivalTime){
        Customer a(++nCustomers, arrivalTime, randServicetime());
        printf("고객 <%d> 방문, 서비스 시간 : ",a.id, a.tService);
        que.enqueue(a);
    }
public :
    BankSimulator()
    : totalWaitTime(0), nServedCustomers(0), nCustomers(0){}
    void readSimulationParameters(){
        printf("시뮬레이션 횟수 입력 : \n");
        scanf("%d",&nSimulation);
        printf("단위시간 당 도착 고객 입력 (ex:0.5) : \n");
        scanf("%lf", &probArrival);
        printf("고객 당  최대 서비스 시간 입력 (Ex:5) : \n");
        scanf("%d", &tMaxService);
    }
    void run(){
        int clock = 0;
        int serviceTime = -1;
        while(clock<nSimulation){
            clock++;
            if(isNewCustomer()) {insertCustomers(clock);}
            if(serviceTime>0) {serviceTime--; }
            else{
                if(que.isEmpty()) {continue;}
                Customer a = que.dequeue();
                nServedCustomers++;
                totalWaitTime += clock-a.tArrival;
                printf("고객 <%d> 서비스 시작!, 대기시간 : ", a.id, clock-a.tArrival);
                serviceTime = a.tService-1;
            }
        }
    }
    void printStats() {
        printf("=================================================\n");
        printf("    서비스 받은 고객수 = %d\n", nServedCustomers);
        printf("    전체 대기 시간    = %d분\n", totalWaitTime);
        printf("    서비스고객 평균대기시간 = %-5.2f분\n",(double)totalWaitTime/nServedCustomers);
        printf("    현재 대기 고객 수 = %d\n",nCustomers - nServedCustomers);
    }

    

}
int main(void){

}