//PROGRAM 8.2
#include "BinaryNode.h"
class BinaryTree{
    BinaryNode* root;
public :
    BinaryTree()
    : root(nullptr) {}
    void setRoot(BinaryNode* n){ root = n; }
    BinaryNode* getRoot(){ return root; }
    bool isEmpty(){ return root == nullptr; }
    int getCount(){
    }
};