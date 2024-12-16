#include <cstdio>
#include <cstdlib>

class BinaryNode{
public :
    int data;
    BinaryNode* right;
    BinaryNode* left;
public :
    BinaryNode(int val = 0, BinaryNode* l = nullptr, BinaryNode* r = nullptr)
    : data(val), left(l), right(r) {}
    ~BinaryNode(){}
    void setData(int val){ data = val; }
    void setLeft(BinaryNode* n){ left = n; }
    void setRight(BinaryNode* n){ right = n; }
    int getData(){return data;}
    BinaryNode* getLeft() {return left;}
    BinaryNode* getRight() {return right;}
    bool isLeaf() {return right==nullptr && left == nullptr; }
};

class BinaryTree{
public :
    BinaryNode* root;
public :
    BinaryTree()
    : root(nullptr){}
    ~BinaryTree(){}
    bool isEmpty(){ return root == nullptr; }
    void preorder(){
        printf("\n preorder : ");
        preorder(root);
    }
    void preorder(BinaryNode* n){
        if(isEmpty()) return;
        printf(" [%c] ", n->getData());
        preorder(n->getLeft());
        preorder(n->getRight());
    }
    int getCount(){ isEmpty() ? 0 : getCount(root); }
    int getCount(BinaryNode* n){
        if(n==nullptr){ return 0; }
        else return 1 + getCount(n->getLeft()) + getCount(n->getRight());
    }
    int getLeafCount(){ isEmpty() ? 0 : getLeafCount(root); }
    int getLeafCount(BinaryNode* n){
        if(n==nullptr) return 0;
        if(n->isLeaf()) return 1;
        else getLeafCount(n->getLeft()) + getLeafCount(n->getRight());
    }
    int getHeight(){ isEmpty() ? 0 : getHeight(root); }
    int getHeight(BinaryNode* n){
        if(n==nullptr) return 0;
        int hLeft = getHeight(n->getLeft());
        int hRight = getHeight(n->getRight());
        return (hLeft > hRight) ? hLeft+1 : hRight+1;
    }
    int calcSize(){ isEmpty() ? 0 : calcSize(root); }
    int calcSize(BinaryNode* n){
        if(n==nullptr) return 0;
        return n->getData() +  calcSize(n->getLeft()) + calcSize(n->getRight());
    }
    int isEven(BinaryNode* n){
        if(n==nullptr || n->getLeft() == nullptr && n->getRight() == nullptr) return true;
        if(n->getLeft() == nullptr || n->getRight() == nullptr) return false;
        return isEven(n->getLeft()) + isEven(n->getRight());
    }
    int isFull(){
        bool ret = isEven(root);
        printf("\n이 트리는 %s\n", ret ? "완전 이진 트리" : "완전 이진 트리가 아님" );
        return ret;
    }

    int checklevel(BinaryNode* p, BinaryNode* n, int level){
        int ll = 0, lr = 0;
        if(p==n){ return level; }
        if(p->getLeft() == nullptr) ll = checklevel(p->getLeft(), n, level+1);
        if(p->getRight() == nullptr) lr = checklevel(p->getRight(), n, level+1);
        return (ll>0) ? ll : lr;
    }
    int level(BinaryNode* n){
        int level = 0;
        if(root != nullptr) { level = checklevel(root, n, 1); }
        printf("\n%s",(level > 0) ?  "노드 레벨 확인" : "트리에 해당 노드 존재 X" );
        return 0;
    }
    bool checkBalanced(BinaryNode* n){
        if(n==nullptr) return true;
        int lh = getHeight(n->getLeft());
        int rh = getHeight(n->getRight());
        int dh = rh - lh;
        if( dh<-1 || dh>1 ) return false;
        if(!checkBalanced(n->getLeft())) return false;
        return (checkBalanced(n->getRight()));
    }
    bool isBalanced(){
        bool ret = checkBalanced(root);
        printf("\n%s", ret ? "균형잡힘" : "균형 잡히지 않음");
        return ret;
    }

    int calcPathlength(BinaryNode* n, int level){
        if(n==nullptr) return 0;
        int llen = calcPathlength(n->left, level+1);
        int rlen = calcPathlength(n->right, level+1);
        return llen + rlen + level;
    }

    int pathlength(){
        int len = calcPathlength(root, 0);
        printf("\n트리 전체 길이 %d", len);
        return len;
    }
    void swapNodes(BinaryNode* n){
        BinaryNode* tmp = n->right;
        n->right = n->left;
        n->left = tmp;
        swapNodes(n->getLeft());
        swapNodes(n->getRight());
    }
    void reverse(){
        swapNodes(root);
    }
    int hasSameNode(BinaryNode* p, BinaryNode* n){
        if(p==nullptr || n==nullptr) return 0;
        if(p == n ) return 1;
        return hasSameNode(p->left,n) + hasSameNode(p->right,n);
    }
    int isDisjointFrom(BinaryNode* p, BinaryNode* n){
        if(p==nullptr || n == nullptr) return 1;
        if(hasSameNode(p,n)) return 0;
        if(hasSameNode(p,n->left)) return 0;
        if(hasSameNode(p,n->right)) return 0;
        return 1;
    }
    bool checkValid(BinaryNode* n){
        if(n==nullptr) return 1;
        if(!isDisjointFrom(n->left, n->right)) return 0;
        if(!checkValid(n->left)) return 0;
        if(!checkValid(n->right)) return 0;
        return 1;
    }
    bool isValid(){
        bool ret = checkBalanced(root);
        return ret;
    }
};

int main(void){}