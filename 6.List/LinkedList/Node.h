#include <cstdio>

class Node{
    int data;
    Node* link;
public :
    Node(int val = 0)
    : data(val), link(nullptr) {}
    ~Node(){}

    Node* getLink(){ return link; }
    void setLink(Node* next){ link = next; }
    bool hasData(int val){ return data == val; }
    void insertNext(Node* N){
        if(N != nullptr){
            N->setLink(link);
            link = N;
        }
    }
    Node* removeNext(){
        Node* removed = link;
        if(removed != nullptr){
            link = removed->link;
        }
        return removed;
    }
    void display(){ printf ("<%2d> ", data); }
    int getData(){ return data; }

};