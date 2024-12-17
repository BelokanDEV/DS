#include <cstdio>

class BinaryNode{
public :
    int data;
    BinaryNode* left;
    BinaryNode* right;
public :
    BinaryNode(int val = 0)
    : data(val) {}
    ~BinaryNode(){}
    void setData(int val){data = val;}
    void setLeft(BinaryNode *n){left =n;}
    void setRight(BinaryNode *n){right =n;}
    int getData(){return data;}
    BinaryNode* getLeft(){return left;}
    BinaryNode* getRight(){return right;}
    bool isLeaf(){return left==nullptr && right==nullptr;}

    void inorder(){
        if(left!=nullptr) left->inorder();
        printf("%2d", data);
        if(right!=nullptr) right->inorder();
    }

    int getCount(){
        int count = 1;
        if(left!=nullptr) count += left->getCount();
        if(right!=nullptr) count += right->getCount();
        return count;
    }
    int getLeafCount(){
        if(isLeaf()) return 1
        int count = 0;
        if(left!=nullptr) count += left->getLeafCount();
        if(right!=nullptr) count += right->getLeafCount();
        return count;
    }
    int getHeight(){
        if(isLeaf()) return 1;
        int hLeft = 0, hRight = 0;
        if(left!=nullptr) hLeft += left->getHeight();
        if(right!=nullptr) hRight += right->getHeight();
        return (left>right) ? hLeft+1:hRight+1;
    }

    BinaryNode* search(int key){
        if(key == data) return this;
        else if(key<data && left!=nullptr)
            left->search(key);
        else if(key>data && right!= nullptr)
            right->search(key);
        return nullptr
    }
    void insert(BinaryNode* n){
        if(data == n->data) return;
        else if(n->data<data){
            if(left==nullptr) left = n;
            else left->insert(n);
        }
        else if(n->data>data){
            if(right==nullptr) right =n;
            else right->insert(n);
        }
    }
};

int main(void){

}