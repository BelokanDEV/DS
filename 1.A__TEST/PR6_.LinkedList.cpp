#include <cstdio>
#include <cstdlib>

class Node{
    int data;
    Node* link;
public :
    Node(int val = 0)
    : data(val),link(nullptr){}
    Node* getLink(){return link; }
    void setLink(Node* next){
        link = next;
    }
    int getData(){return data; }
    bool hasData(int e){return (e==data);}
    void insertNext(Node* next){
        if(next!=nullptr){
            next->setLink(link);
            link = next;
        }
    }
    Node* removeNext(){
        Node* removed = link;
        if(removed!=nullptr){
            link = removed->link;
        }
        return removed;
    }
    void display(){
        printf("<%d> ",data);
    }
};
class LinkedList{
    Node org;
public :
    LinkedList(){}
    ~LinkedList(){}
    void clear(){while(isEmpty()) delete remove(0);}
    Node* getHead(){ return org.getLink(); }
    bool isEmpty() { return getHead() == nullptr; }
    Node* getEntry(int pos){
        Node* n = &org;
        for(int i = -1; i<pos; i++, n = n->getLink()){
            if(n==nullptr) break;
        }
        return n;
    }
    void insert(int pos, Node* n){
        Node* prev = getEntry(pos-1);
        if(prev!=nullptr){
            prev->insertNext(n);
        }
    }
    Node* remove(int pos){
        Node* prev = getEntry(pos-1);
        if(prev!=nullptr){
            prev->removeNext();
        }
    }
    Node* find(int val){
       for(Node* p = getHead(); p!=nullptr; p=p->getLink()){
        if(p->hasData(val)) return p;
       }
       return nullptr;
    }
    Node* replace(int pos, Node* n){
        Node* prev = getEntry(pos-1);
        if(prev!=nullptr){
            delete prev->removeNext();
            prev->insertNext(n);
        }
    }
    int size(){
        int count = 0;
        for(Node* p = getHead(); p!=nullptr; p=p->getLink()){
            count++;
        }
        return count;
    }
    void display(char* str = "List"){
        printf("[%s]",str);
        for(Node* p = getHead(); p!= nullptr; p=p->getLink()){
            p->display();
        }
        printf("\n");
    }
    void reverse(){
        Node* prev = getEntry(-1);
        Node* n = prev->getLink();
        Node* next;
        
        prev->setLink(nullptr);
        while(n!=nullptr){
            next = n->getLink();
            prev->insertNext(n);
            n = next;
        }
    }
    void merge(LinkedList* that){
        Node* p = &org;
        for(; p->getLink()!=nullptr; p=p->getLink(););

        p->setLink(that->org.getLink());
        that->org.setLink(nullptr);
    }
};
class SparsePoly{
    int expo;
    float coef;
public :
    SparsePoly()
    : expo(0), coef(0) {}
    void read()
}
//clear gethead isempty getentry insert remove replace find size display
// + reverse, merge
int main(void)
{
    LinkedList list;
    list.insert( 0, new Node(10) );
    list.insert( 0, new Node(20) );
    list.insert( 1, new Node(30) );
    list.insert( list.size(), new Node(40) );
    list.insert( 2, new Node(50) );
    list.display();
    list.reverse();
    list.display();
    list.remove(2);
    list.remove(list.size()-1);
    list.remove(0);
    list.replace(1, new Node(90));
    list.display();
    list.clear();
    list.display();
    return 0;
}