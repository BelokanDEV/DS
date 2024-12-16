#include <cstdio>
class BinaryNode{
    int data;
    BinaryNode* left;
    BinaryNode& right;
public :
    void setData(int value){ data = value; }
    void setLeft(BinaryNode* n){left = n;}
    void setRight(BinaryNode*n){right = n;}
    int getData(){return data;}
    BinaryNode* getLeft(){return left;}
    BinaryNode* getRight(){return right;}
    bool isLeaf(){return left==nullptr && right==nullptr; }

    void inorder() {
        if (left!=nullptr) left->inorder();
        printf("[%2d]",data);
        if (right!=nullptr) right-> inorder();
    }
    void preorder() {
        printf("[%2d]",data);
        if(left!=nullptr) left->preorder();
        if(right!=nullptr) right->preorder();
    }
    void postorder() {
        if(left!=nullptr) left->postorder();
        if(right!=nullptr) right->postorder();
        printf("[%2d]",data);
    }

    int getCount() {
        int count = 1;
        if (left!=nullptr) count += left->getCount();
        if (right!=nullptr) count += right->getCount();
        return count;
    }
    int getLeafCount() {
        if(isLeaf()) return 1;
        int count = 0;
        if(left!=nullptr) count += left->getLeafCount();
        if(right!=nullptr) count += right->getLeafCount();
        return count;
    }
    int getHeight(){
        if(isLeaf()) return 1;
        int hLeft = 0, hRight = 0;

        if(left != nullptr) hLeft = left->getHeight();
        if(right != nullptr ) hRight = right->getHeight();

        return (hLeft>hRight) ? hLeft  + 1 : hRight + 1;
    }

    BinaryNode* search(int key) {
        if(key == data)
            return this;
        else if (key < data && left != nullptr)
            return left->search(key);
        else if (key > data && right != nullptr)
            return right->search(key);
        return nullptr;
    }

    void insert(BinaryNode* n){
        if(data == n->data) return;
        else if (n->data < data) {
            if (left == nullptr ) left = n;
            else left->insert(n);
        }
        else if (n->data > data) {
            if (right == nullptr ) right = n;
            else right->insert(n); 
        }
    }
    
};
