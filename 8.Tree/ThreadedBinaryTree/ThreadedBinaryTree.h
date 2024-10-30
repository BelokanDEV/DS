#include "ThreadedBinNode.h"

class ThreadedBinTree{
    ThreadedBinNode* root;
public :
    ThreadedBinTree()
    : root(nullptr) {}
    void setRoot(ThreadedBinNode* n){ root = n; }
    ThreadedBinNode* getRoot(){ return root; }
    bool isEmpty(){ return root == nullptr; }
    void threadedInorder(){
        if(!isEmpty()){
            printf("스레드 이진 트리: ");
            ThreadedBinNode *q = root;
            while(q->getLeft())
                q = q->getLeft();
            do{
                printf("%c ", q->getData());
                q = findSuccessor(q);
            } while(q);
            printf("\n");
        }
    }
private :
    ThreadedBinNode* findSuccessor(ThreadedBinNode *p){
        ThreadedBinNode *q = p->getRight();
        if( q==nullptr || p->bThread ) return q;
        while(q->getLeft()!=nullptr) q = q->getLeft();
        return q;
    }
};