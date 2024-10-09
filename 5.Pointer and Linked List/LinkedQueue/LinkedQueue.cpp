#include "LinkedQueue.h"
int main(void){
    LinkedQueue que;
    for(int i = 1 ; i<10 ; i++){
        que.enqueue(new Node(i)); //Node(i)가 생성자, 동적할당으로 생성
    }
    que.display();
    delete que.dequeue();
    delete que.dequeue();
    delete que.dequeue();
    que.display();
    return 0;
}