#include "Node.h"

class LinkedQueue{
    Node* front;
    Node* rear;
    public :
    LinkedQueue(){ front = rear = NULL; }
    ~LinkedQueue() { 
        while (!isEmpty()) {
            delete dequeue();
        }
    }
    bool isEmpty() {return ((front == NULL)&&(rear == NULL)); }
    void enqueue (Node* e){
        if( !isEmpty() ){
            rear->link = e;
            rear = e;
        }
        else{
            front = rear = e;
        }
    }
    Node* dequeue (){
        Node* p = front;
        front = p->link;
        return p;
    }
    Node* peek(){ return front; }
    void display(){
        printf("큐 내용 : ")
        for(Node* i = front; (*i) != NULL; i = i->getLink()){
            i->display();
        }
        printf("\n")
    }
};