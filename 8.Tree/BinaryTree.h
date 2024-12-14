#include "BinaryNode.h"

class BinaryTree{
    BinaryNode* root;
public :
    BinaryTree()
    : root(nullptr) {}
    void setRoot(BinaryNode* n){root = n;}
    BinaryNode* getRoot(){return root;}
    bool isEmpty(){return root = nullptr; }

    void inorder(){
        printf("\n inorder : ");
        inorder(root);
    }
    void preorder(){
        printf("\n preorder : ");
        preorder(root);
    }
    void postorder(){
        printf("\n postorder : ");
        postorder(root);
    }
    int getCount(){}
    int getHeight(){}
    int getLeftCount(){}

private :
    void inorder(BinaryNode* n){
        if(n != nullptr){
            inorder(n->getLeft());
            printf(" [%c] ", n->getData());
            inorder(n->getRight());
        }
    }
    void preorder(BinaryNode* n){
        if(n != nullptr){
            printf(" [%c] ", n->getData());
            preorder(n->getLeft());
            preorder(n->getRight());
        }
    }
    void postorder(BinaryNode* n){
        if(n != nullptr){
            postorder(n->getLeft());
            postorder(n->getRight());
            printf(" [%c] ", n->getData());
        }
    }
    int getCount(BinaryNode* n){
        if(n==nullptr) return 0;
        return 1 + getCount(n->getLeft()) + getCount(n->getRight()); 
    }
};