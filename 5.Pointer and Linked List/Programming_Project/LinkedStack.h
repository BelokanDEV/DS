#include "Location2D.h"
class LinkedStack{
    Location2D* top;
    public :
    LinkedStack() { top = NULL; }
    ~LinkedStack() { while(!isEmpty()) delete pop(); }
    bool isEmpty() { return top == NULL; }
    void push (Location2D* p) {
        if( isEmpty() ) top = p;
        else {
            p->setLink( top );
            top = p;
        }
    }
    Location2D* pop() {
        if( isEmpty() ) { return NULL;}
        Location2D* p = top;
        top = p->getLink();
        return p;
    }
    Location2D* peek() {
        return top;
    }
    void display() {
        printf("[LinkedStack]\n");
        for(Location2D* p = top; p!=NULL; p=p->getLink()) { p->display(); }
        printf("\n");
    }
    int size() {
        int count = 0;
        Location2D* temp = top;
        while(top!=NULL){
            count++;
            temp = temp->getLink();
        }
        return count;
    }
};