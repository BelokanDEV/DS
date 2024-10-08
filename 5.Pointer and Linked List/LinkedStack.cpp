#include "LinkedStack.h"
int main(void){
    LinkedStack stack;
    stack.push( new Node(2015130007, "홍길동", "소프트웨어학부"));
    stack.push( new Node(2015130100, "이순신", "전자정보공학부"));
    stack.push( new Node(2015130135, "황희", "경제학과"));
    stack.display();

    Node* node = stack.pop();
    printf("[POP항목]\n");
    node->display();
    printf("\n");
    delete node;
    stack.display();
    return 0;
}