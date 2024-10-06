#include "CircularQueue.h"

int main(void){
    CircularQueue a;
    a.enqueue(3);
    a.enqueue(5);
    a.enqueue(7);
    a.dequeue();
    a.dequeue();
    a.dequeue();
    a.enqueue(5);
    a.enqueue(8);
    a.enqueue(2);
    a.enqueue(6);
    a.display();

    return 0;
}
