#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAX_QUEUE_SIZE 20
inline void error(char* str){
    printf("%s", str);
    exit(1);
}

struct Customer{
    int id;
    int tArrival;
    int tService;
    Customer(int i = 0, int tArr = 0, int tSer = 0)
    : id(i), tArrival(tArr), tService(tSer){}
};

class CustomerQueue{
    Customer data[MAX_QUEUE_SIZE];
    int front;
    int rear;
public :
    CustomerQueue()
    : front(0), rear(0) {}
    bool isEmpty(){ return front == rear; }
    bool isFull(){ return front == (rear+1)%MAX_QUEUE_SIZE; }
    void enqueue(Customer n){
        if( isFull( )) { error("QUEUE IS FULL"); }
        rear = (rear+1)%MAX_QUEUE_SIZE;
        data[rear] = n;
    }
    Customer dequeue(){
        if( isEmpty( )) { error("QUEUE IS EMPTY"); }
        front = (front+1)%MAX_QUEUE_SIZE;
        return data[front];
    }
};

class BankSimulator{
    int nSimulation;
    double probArrival;
    int tMaxService;

    int totalWaitTime;
    int nServedCustomers;
    int nCustomers;
    CustomerQueue que;

    double Random(){ return rand()/(double)RAND_MAX; }
    bool isNewCustomer() { return probArrival>Random(); }
    int randServicetime() {return (int)(Random()*tMaxService)+1; }
    void insertCustomers(int arrivalTime){
        Customer a(++nCustomers, arrivalTime, randServicetime());
        printf("고객 <%d> 방문, 서비스 시간 : %d\n",a.id, a.tService);
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
            printf("현재시각 = %d\n",clock);
            if(isNewCustomer()) {insertCustomers(clock);}
            if(serviceTime>0) {serviceTime--; }
            else{
                if(que.isEmpty()) {continue;}
                Customer a = que.dequeue();
                nServedCustomers++;
                totalWaitTime += clock-a.tArrival;
                printf("고객 <%d> 서비스 시작!, 대기시간 : %d\n", a.id, clock-a.tArrival);
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
};

int main() {
    srand( (unsigned int) time(NULL) );
    BankSimulator sim;
    sim.readSimulationParameters();
    sim.run();
    sim.printStats();
    return 0;
}