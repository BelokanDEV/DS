#include <cstdio>

struct Node{
    int data;
    Node* link;
public :
    Node()
    : data(0), link(nullptr){}
    Node* getLink(){
        return link;
    }
    void setLink(Node* n){
        link = n;
    }
    void insertNext(Node* n){
        n->setLink(link);
        link = n;
    }
    Node* removeNext(){
        Node* temp = link;
        if(temp != nullptr){
            link = temp->link;
        }
        return temp;
    }
    void display(){
        printf("<%2d>", data);
    }
};

class LinkedStack{
    Node* top;
public :
    LinkedStack()
    : top(nullptr) {}
    bool isEmpty(){return top ==nullptr;}

    void push(Node* n){
       if(isEmpty()){ top = n; }
       n->setLink(top);
       top = n;
    }
    Node* pop(Node* n){
        if(isEmpty()) { return nullptr; }
        Node* temp = top;
        top = top->getLink();
        return temp;
    }
};
class LinkedQueue{
    Node* front;
    Node* rear;
public :
    LinkedQueue()
    : front(nullptr), rear(nullptr) {}

    bool isEmpty(){return front == nullptr; }
    void enqueue(Node* n){
        if(isEmpty()){front = rear = n;}
        rear->setLink(n);
        rear = n;
    }
    Node* dequeue(){
        if(isEmpty()){return nullptr; }
        Node* temp = front;
        front = temp->getLink();
        return temp;
    }
};