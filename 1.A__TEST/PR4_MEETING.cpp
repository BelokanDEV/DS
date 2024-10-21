#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define MAX_QUEUE_SIZE 20
static char bName[10][32] = { "병길", "성우", "경철", "용주", "영락", "영규", "광만", "형석", "남용", "용철" };
static char gName[10][32] = { "은아", "외자", "태수", "영선", "미정", "미영", "선아", "욱희", "산혜", "소정" };

struct Customer{
    int id;
    int tArrival;
    char name[20];
public :
    Customer(int i = 0, int tArr = 0, char* n = "??")
    : id(i), tArrival(tArr){
        strcpy(name,n);
    }
};

class CustomerQueue{
    Customer data[MAX_QUEUE_SIZE];
    int front;
    int rear;
public :
    CustomerQueue()
    : front(0),rear(0){}
    bool isEmpty(){return front==rear;}
    bool isFull(){return front==(rear+1)%MAX_QUEUE_SIZE;}
    void enqueue(Customer n){
        rear = (rear+1)%MAX_QUEUE_SIZE;
        data[rear] = n;
    }
    Customer dequeue(){
        front = (front+1)%MAX_QUEUE_SIZE;
        return data[front];
    }
};
class MeetingSimulator{
private :
    int nSimulation;
    double probArrival;
    int tMaxService;

    int nCustomers;
    int nCouples;
    int totalwaitboys;
    int totalwaitgirls;
    int totalRemainboys;
    int totalRemaingirls;
    CustomerQueue qBoys, qGirls;
    double Random(){ return rand()/(double)RAND_MAX;}
    bool isNewCustomer() {return probArrival>Random(); }
    int randGender() {return rand()%2; }

    void insertNewCustomer(int arrivalTime){
        Customer a;
        a.id = ++nCustomers;
        a.tArrival = arrivalTime;
        if(randGender()){
            strcpy(a.name,bName[rand()%10]);
            printf("남학생 등록, 이름 : %s\n",a.name);
            qBoys.enqueue(a);
        }
        else{
            strcpy(a.name,gName[rand()%10]);
            printf("여학생 등록, 이름 : %s\n",a.name);
            qGirls.enqueue(a);
        }
    }
public :
    MeetingSimulator()
    : nCustomers(0), nCouples(0), totalwaitboys(0), totalwaitgirls(0), totalRemainboys(0), totalRemaingirls(0){}
    void init(){
        nCustomers = nCouples = 0;
        totalwaitboys = totalwaitgirls = 0;
    }
    void readParameters(){
        printf("시뮬레이션 횟수 입력 (ex:5) = \n");
        scanf("%d",&nSimulation);
        printf("단위 시간 당 예상 도착 고객 수 (ex=0.5) = \n");
        scanf("%lf", &probArrival);
    }
    void run(){
        Customer a,b;
        int clock = 0;
        while(clock<nSimulation){
            clock++;
            printf("[%d]\n",clock);
            if(isNewCustomer()){ insertNewCustomer(clock); }
            if((!qBoys.isEmpty())&&(!qGirls.isEmpty())){
                a = qBoys.dequeue();
                b = qGirls.dequeue();
                printf("커플 성사! %s와 %s (대기시간 %d, %d)", a.name, b.name, clock-a.tArrival, clock-b.tArrival);
                totalwaitboys += clock-a.tArrival;
                totalwaitgirls += clock-b.tArrival;
                nCouples++;
            }
        }
        while(qBoys.isEmpty()){
            a = qBoys.dequeue();
            totalwaitboys += clock-a.tArrival;
            totalRemainboys++;
        }
        while(qGirls.isEmpty()){
            b = qGirls.dequeue();
            totalwaitgirls += clock-b.tArrival;
            totalRemaingirls++;
        }
    }
    void printstats(){
        printf("총 고객 수 : %d\n",nCustomers);
        printf("총 성사된 커플 수 : %d\n",nCouples);
        printf("남자 고객 평균 대기 시간 : %lf\n",(double)totalwaitboys/(nCouples+totalRemainboys));
        printf("여자 고객 평균 대기 시간 : %lf\n",(double)totalwaitgirls/(nCouples+totalRemaingirls));
    }
};
int main(void){
    srand((unsigned int) time(NULL));
    MeetingSimulator sim;
    sim.init();
    sim.readParameters();
    sim.run();
    sim.printstats();
    return 0;
}