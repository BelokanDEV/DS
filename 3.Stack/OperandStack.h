// OperandStack.h : 피연산자 클래스

#include <cstdio>
#include <cstdlib>
inline void error(char* str){
    printf("%s",str);
    exit(1);
}
const int MAX_STACK_SIZE = 20;
class OperandStack{
    private : 
    double data[MAX_STACK_SIZE];
    int top = -1;
    public :
    bool isEmpty(){ return top == -1; }
    bool isFull(){ return top == MAX_STACK_SIZE -1; }
    void push(double e){
        if(isFull()){ error("THIS STACK IS FULL"); }
        else { data[++top] = e; }
    }
    double pop(){
        if(isEmpty()){ error("THIS STACK IS EMPTY"); }
        else { return data[top--];}
    }
};
