#include "BinaryNode.h"

class BinaryTree{
public :
    BinaryNode* root;
    BinaryTree()
    : root(nullptr) {}
    void setRoot(BinaryNode* n){root = n;}
    BinaryNode* getRoot(){return root;}
    bool isEmpty(){return root == nullptr; }

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
    int getCount(){
        return isEmpty() ? 0 : getCount(root);
    }
    int getLeafCount(){
        return isEmpty() ? 0 : getLeafCount(root);
    }
    int getHeight(){
        return isEmpty() ? 0 : getHeight(root);
    }

private :
    void inorder(BinaryNode* n){
        if(n != nullptr){
            inorder(n->getLeft());
            printf(" [%d] ", n->getData());
            inorder(n->getRight());
        }
    }
    void preorder(BinaryNode* n){
        if(n != nullptr){
            printf(" [%d] ", n->getData());
            preorder(n->getLeft());
            preorder(n->getRight());
        }
    }
    void postorder(BinaryNode* n){
        if(n != nullptr){
            postorder(n->getLeft());
            postorder(n->getRight());
            printf(" [%d] ", n->getData());
        }
    }
    int getCount(BinaryNode* n){
        if(n==nullptr) return 0;
        else return 1 + getCount(n->getLeft()) + getCount(n->getRight()); 
    }
    int getLeafCount(BinaryNode* n){
        if(n==nullptr) return 0;
        if(n->isLeaf()) return 1;
        else return  getLeafCount(n->getLeft()) + getLeafCount(n->getRight());
            
    }
    int getHeight(BinaryNode* n){
        if(n==nullptr) return 0;
        int hLeft = getHeight(n->getLeft());
        int hRight = getHeight(n->getRight());
        return (hLeft>hRight) ? hLeft+1 : hRight+1;
    }
};