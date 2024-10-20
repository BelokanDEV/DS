#include "Node2.h"
class DblLinkedList {
    Node2 org;
public :
    DblLinkedList() : org(0) {}
    ~DblLinkedList() { while(!isEmpty()) delete remove(0); }
    Node2* getHead() { return org.getNext(); }
    bool isEmpty() { return getHead()==nullptr; }

    Node2* getEntry(int pos){
        Node2* n = &org;
        for( int i = -1; i < pos; i++, n = n->getNext())
           { if(n==nullptr) break; }
        return n;
    }
    void insert(int pos, Node2* n){
        Node2* prev = getEntry(pos-1);
        if(prev != nullptr) { prev->insertNext(n);}
    }
    Node2* remove(int pos){
        Node2* n = getEntry(pos);
        return n->remove();
    }
    Node2* find(int val){
        for(Node2* p = getHead() ; p != nullptr ; p=p->getNext())
            { if (p->hasData(val)) return p;}
        return nullptr;
    }
    void replace(int pos, Node2 *n){
        Node2* prev = getEntry(pos-1);
        if( prev != nullptr ){
            delete prev->getNext()->remove();
            prev->insertNext(n);
        }
    }
    int size(){
        int count = 0;
        for(Node2* p = getHead() ; p != nullptr ; p = p->getNext()) { count++; }
        return count;
    }
    void display(){
        printf(" [이중연결리스트 항목 수 = %2d] : ", size());
        for(Node2* p = getHead() ; p != nullptr ; p = p->getNext())
            p->display();
        printf(" \n");
    }
    void clear() { while(!isEmpty()) delete remove(0); }
};