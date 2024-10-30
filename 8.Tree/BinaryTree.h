//PROGRAM 8.2
#include "CircularQueue.h"

class BinaryTree{
    BinaryNode* root;
public :
    BinaryTree()
    : root(nullptr) {}
    void setRoot(BinaryNode* n){ root = n; }
    BinaryNode* getRoot(){ return root; }
    bool isEmpty(){ return root == nullptr; }
    void inorder(){ printf("\n  inorder : "); inorder(root); }
    void preorder(){ printf("\n preorder : "); preorder(root); }
    void postorder(){ printf("\n postorder : "); postorder(root); }
    void levelorder( ){
        printf("\nlevelorder : ");
        if(!isEmpty()){
            CircularQueue q;
            q.enqueue(root);
            while(!q.isEmpty()){
                BinaryNode* n = q.dequeue();
                if(n != nullptr){
                    printf(" [%c] ", n->getData());
                    q.enqueue(n->getLeft());
                    q.enqueue(n->getRight());
                }
            }
        }
        printf("\n");
    }
    int getCount() {return isEmpty() ? 0 : getCount(root); }
    int getLeafCount() {return isEmpty() ? 0 : getLeafCount(root); }
    int getHeight() {return isEmpty() ? 0 : getHeight(root); }
    int evaluate() { return evaluate(root); } // 후위 수식 연산
private :
    void inorder(BinaryNode* node) { // LVR
        if(node!=nullptr) {
            inorder(node->getLeft());
            printf(" [%c] ", node->getData());
            inorder(node->getRight());
        }
    }
    void preorder(BinaryNode* node) { // VLR
        if(node!=nullptr) {
            printf(" [%c] ", node->getData());
            preorder(node->getLeft());
            preorder(node->getRight());
        }
    }
    void postorder(BinaryNode* node) { // LRV
        if(node!=nullptr) {
            postorder(node->getLeft());
            postorder(node->getRight());
            printf(" [%c] ", node->getData());
        }
    }
    int getCount(BinaryNode *node){
        if(node==nullptr) return 0;
        return 1 + getCount(node->getLeft()) + getCount(node->getRight());
    }
    int getLeafCount(BinaryNode *node){
        if(node==nullptr) return 0;
        if(node->isLeaf()) return 1;
        else return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
    }
    int getHeight(BinaryNode *node){
        if(node==nullptr) return 0;
        int hLeft = getHeight(node->getLeft());
        int hRight = getHeight(node->getRight());
        return (hLeft>hRight) ? hLeft+1 : hRight+1;
    }
    int evaluate(BinaryNode *node){
        if(node == nullptr) return 0;
        if(node->isLeaf()) return node->getData();
        else{
            int op1 = evaluate(node->getLeft());
            int op2 = evaluate(node->getRight());
            switch(node->getData()){
                case '+' : return op1+op2;
                case '-' : return op1-op2;
                case '*' : return op1*op2;
                case '/' : return op1/op2;
            }
            return 0;
        }
    }
};