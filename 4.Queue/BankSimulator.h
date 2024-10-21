#include "CustomerQueue.h"
class BankSimulator
{
    int nSimulation;            // 입력 : 전체 시뮬레이션 횟수
    double probArrival;         // 입력 : 단위시간에 도착하는 평균 고객 수
    int tMaxService;            // 입력 : 한 고객에 대한 최대 서비스 시간
    int totalWaitTime;          // 결과 : 고객들이 기다린 전체시간
    int nCustomers;             // 결과 : 전체 고객 수
    int nServedCustomers;       // 결과 : 서비스 받은 고객 수
    CustomerQueue que;          // 고객 대기 큐

    // 랜덤 숫자를 생성하여 고객 도착 여부와 서비스 시간 자동 생성 코드
    double Random() { return rand()/(double)RAND_MAX; } //0과 1 사이의 난수 리턴
    bool isNewCustomer() { return Random() < probArrival;}
    int RandServiceTime() { return (int)(tMaxService*Random())+1;}

    void InsertCustomer( int arrivalTime ) {
        Customer a(++nCustomers, arrivalTime, RandServiceTime());
        printf(" 고객 %d 방문 (서비스 시간 : %d분)\n", a.id, a.tService);
        que.enqueue( a );
    }

    public :
    BankSimulator()
    :nCustomers(0),totalWaitTime(0),nServedCustomers(0){}

    void readSimulationParameters() {
        printf("시뮬레이션 할 시간 (예:10) = ");
        scanf("%d", &nSimulation);
        printf("단위시간에 도착하는 고객 수 (예:0.7 = ) = ");
        scanf("%lf", &probArrival);
        printf("한 고객에 대한 최대 서비스 시간 (예:5) = ");
        scanf("%d", &tMaxService);
        printf("=================================================\n");
    }

    void run() {
        int clock = 0;
        int serviceTime = -1;
        while(clock < nSimulation){
            clock++;
            printf("현재시각=%d\n", clock);

            if ( isNewCustomer() ) { InsertCustomer(clock); } // 랜덤하게 새로운 고객 입장
            
            if ( serviceTime > 0) { serviceTime--; } // 현재 고객 서비스 중
            else { //서버가 서비스 중이 아닐 경우
                if (que.isEmpty() ) continue; // 기다리는 고객이 없을경우 continue
                Customer a = que.dequeue(); 
                nServedCustomers++;
                totalWaitTime += clock-a.tArrival;
                printf(" 고객 %d 서비스 시작 (대기시간 : %d분)\n", a.id, clock-a.tArrival);
                serviceTime = a.tService - 1; 
                // 잔여시간 = 서비스 소요시간 - 1 (현재 단위시간 1을 소모하여 처리했으므로)
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