#include "BinaryTree.h"

class BinSrchTree : public BinaryTree
{
public :
    BinSrchTree(void){}
    ~BinSrchTree(void){}
    BinaryNode* search(int key){
        BinaryNode* node = search(root, key);
        if(node!=nullptr){
            printf(" 탐색 성공 : 키값이 %d인 노드 = 0x%x\n", node->getData(), node);
        }
        else { 
            printf(" 탐색 실패 : 키값이 %d인 노드 없음\n", key);
        }
        return node;
    }
    void insert(BinaryNode* n){
        if(n == nullptr) return;
        if(isEmpty()) root = n;
        else insert(root,n);
    }
    void remove(int key){
        if(isEmpty()) return;
        BinaryNode* parent = nullptr;
        BinaryNode* node = root;
        while( node != nullptr && node->getData() != key) {
            parent = node;
            node = (key < node->getData()) ? node->getLeft() : node->getRight();
        }
        if( node == nullptr ){
            printf(" Error : key is not in the tree\n");
            return;
        }
        else remove(parent, node);
    }

private :
    BinaryNode* search(BinaryNode* n, int key){
        if(n == nullptr) return nullptr;
        if(key == n->getData()) { return n; }
        else if (key < n->getData()) { return search(n->getLeft(),key); }
        else {return search(n->getRight(), key); }
    }

    void insert(BinaryNode* r, BinaryNode* n){
        if(n->getData() == r->getData()) { return; }
        else if(n->getData()<r->getData()){
            if(r->getLeft()==nullptr){
                r->setLeft(n);
            }
            else{
                insert(r->getLeft(), n);
            }
        }
        else{
            if(r->getRight()==nullptr){
                r->setRight(n);
            }
            else{
                insert(r->getRight(),n);
            }
        }
    }
    void remove(BinaryNode* parent, BinaryNode *node){
        if(node->isLeaf()){
            if(parent == nullptr) { root = nullptr; }
            else{
                if( parent->getLeft() == node )
                    parent->setLeft(nullptr);
                else if ( parent->getRight() == node )
                    parent->setRight(nullptr);
            }
        }
        else if (node->getLeft()==nullptr || node->getRight()==nullptr){
            BinaryNode* child = (node->getLeft() != nullptr) ? node->getLeft() : node->getRight();
            if(node == root) { root = child; }
            else{
                if(parent->getLeft() == node) { parent->setLeft(child);}
                else { parent->setRight(child); }
            }
        }
        else{
            BinaryNode* succp = node;
            BinaryNode* succ = node->getRight();
            while(succ->getLeft()!=nullptr){
                succp = succ;
                succ = succ->getLeft();
            }
            if( succp ->getLeft() == succ)
                succp->setLeft(succ->getRight());
            else
                succp->setRight(succ->getRight());
            node->setData(succ->getData());
            node = succ;
        }
        delete node;
    }
};