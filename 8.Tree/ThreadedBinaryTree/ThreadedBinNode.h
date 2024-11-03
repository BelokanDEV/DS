#include <cstdio>
class ThreadedBinNode{
    int data;
    ThreadedBinNode* left;
    ThreadedBinNode* right;
public :
    bool bThread;
    ThreadedBinNode(int val, ThreadedBinNode* l, ThreadedBinNode* r, bool bTh)
    : data(val), left(l), right(r), bThread(bTh) {}
    void setRight(ThreadedBinNode* n){right = n;}
    int getData(){return data;}
    ThreadedBinNode* getLeft(){return left;}
    ThreadedBinNode* getRight(){return right;}
};