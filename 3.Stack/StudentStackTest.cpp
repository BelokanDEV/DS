#include <cstdio>
#include "StudentStack.h"
#include "Student.h"

int main(void){
    StudentStack SS;
    SS.push( Student(2377, "조명근", "소프트웨어학부") );
    SS.push ( Student(2379, "일론머스크", "산업경영공학부"));
    SS.display();
    return 0;
}