#pragma once
#include <cstdio>
#include <cstdlib>
#include "Student.h"

inline void error(const char *message){
    printf("%s\n", message);
    exit(1); //cstlib 라이브러리에서 지원하는 프로그램 종료함수
}

const int MAX_SIZE_STACK = 10;

class StudentStack{
    private :
    int top;
    Student data[MAX_SIZE_STACK];
    
    public :
    StudentStack(){ top = -1; }
    ~StudentStack(){}
    bool isEmpty(){ return top == -1; }
    bool isFull(){ return top == MAX_SIZE_STACK -1; }
    
    void push(Student e){
        if ( isFull() == true ) { error("THIS STACK IS FULL"); }
        else{
            data[++top] = e;
        }
    }
    Student pop(){
        if ( isEmpty() == true ) { error("THIS STACK IS EMPTY"); }
        else return data[top--];
    }
    Student peek(){
        if ( isEmpty() == true ) { error("THIS STACK IS EMPTY"); }
        else return data[top];
    }
    void display(){
        printf("Stack elements: \n");
        for(int i = 0; i<=top; i++){
            data[i].display();
        }
    }
};