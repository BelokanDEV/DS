#include <cstdio>

class Node{
    Node* link;
    int data;
public :
    Node* getLink(){ return link; }
    void setLink(Node* next){link = next;}
    void display{printf(" <%2d> ",data)};
}
class LinkedList{
    Node* head;

}