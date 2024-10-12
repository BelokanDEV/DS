#include "Node.h"
class LinkedList{
    Node org;
public :
    LinkedList(){}
    ~LinkedList(){}
    void clear() { while(!isEmpty()) delete remove(0); }
    Node* getHead() { return org.getLink(); }
    bool isEmpty() { return getHead() == NULL; }

    Node* getEntry(int pos){
        Node* n = &org;
        for(int i = -1 ; i<pos ; i++, n = n->getLink())
            if( n == NULL) break;
        return n;
    }
    void insert(int pos, Node* n){
        Node* prev = getEntry(pos-1);
        if( prev != nullptr)
            prev->insertNext(n);
    }
    Node* remove(int pos) {
        Node* prev = getEntry(pos-1);
        return prev->removeNext();
    }

    Node* find(int val){
        for( Node* p = getHead() ; p != NULL ; p = p->getLink() )
            if( p->hasData( val )) return p;
        return nullptr;
    }

    void replace(int pos, Node *n){
        Node* prev = getEntry(pos-1);
        if( prev != nullptr ){
            delete prev->removeNext();
            prev->insertNext(n);
        }
    }
    int size(){
        int count = 0;
        for( Node* p = getHead(); p!=nullptr; p=p->getLink())
            count++;
        return count;
    }
    void display() {
        printf(" [전체 항목 수 = %2d] : ", size());
        for( Node *p = getHead(); p != nullptr; p=p->getLink() )
            p->display();
        printf("\n");
    }
};