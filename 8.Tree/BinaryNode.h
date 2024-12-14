#include <cstdio>

class BinaryNode{
protected:
    int data;
    BinaryNode* left;
    BinaryNode* right;
public :
    BinaryNode(int val = 0, BinaryNode* l = nullptr, BinaryNode* r = nullptr)
    : data(val), left(l), right(r) {}
    void setData (int val) {data = val;}
    void setLeft (BinaryNode* n) {left = n;}
    void setRight (BinaryNode* n) {right = n;}
    int getData() {return data;}
    BinaryNode* getLeft() {return left;}
    BinaryNode* getRight() {return right;}
    bool isLeaf() {return (left==nullptr)&&(right==nullptr); }
};