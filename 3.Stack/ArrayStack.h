#include <cstdio>
#include <cstdlib>

inline void error(const char *message){
    printf("%s\n", message);
    exit(1); //cstlib 라이브러리에서 지원하는 프로그램 종료함수
}

const int MAX_SIZE_STACK = 10;

class ArrayStack{
    private :
    int top;
    int data[MAX_SIZE_STACK];
    
    public :
    ArrayStack(){ top = -1; }
    ~ArrayStack(){}
    bool isEmpty(){ return top == -1; }
    bool isFull(){ return top == MAX_SIZE_STACK -1; }
    
    void push(int item){
        if ( isFull() == true ) { error("THIS STACK IS FULL"); }
        else{ data[++top] = item; }
    }
    int pop(){
        int e;
        if ( isEmpty() == true ) { error("THIS STACK IS EMPTY"); }
        else{ e = data[top--]; }
        return e;
    }
    int peek(){
        int e;
        if ( isEmpty() == true ) { error("THIS STACK IS EMPTY"); }
        else{ e = data[top]; }
        return e;
    }
    void display(){
        printf("Stack elements: \n");
        for(int i = top; i>=0; i--){
            printf("|  %d  | <-- data[%d]\n",data[i], i);
        }
        printf("\\_____\/ \n");
    }
};