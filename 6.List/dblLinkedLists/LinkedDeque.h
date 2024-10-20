#include "DblLinkedList.h"
class LinkedDeque : public DblLinkedList
{
public :
    void addFront (Node2* n) { insert(0, n); }
    Node2* deleteFront () { return remove(0); }
    Node2* getFront() {return getEntry(0); }
    void addRear (Node2* n) {insert(size(), n); }
    Node2* deleteRear() { return remove(size()-1);}
    Node2* getRear() { return getEntry(size()-1); }
};

int main(void){
    LinkedDeque deq;
    for(int i = 1; i<10; i++){
        if(i%2) deq.addFront( new Node2(i) );
        else deq.addRear( new Node2(i) );
    }
    deq.display();
    delete deq.deleteFront();
    delete deq.deleteRear();
    delete deq.deleteFront();
    deq.display();
}