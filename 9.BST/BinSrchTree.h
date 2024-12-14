#include "BinaryTree.h"

class BinSrchTree : public BinaryTree
{
public :
    BinSrchTree(){}
    ~BinSrchTree(){}

    BinaryNode* search(int key){
        BinaryNode* node = searchRecur(root, key);
        if(node!=nullptr) printf("탐색 성공 : 키값이 %d인 노드 = 0x%x\n", node->getData(), node);
         else printf("탐색 실패 : 키값이 %d인 노드 없음\n", key);
        return node;
    }
    void insert(BinaryNode* n){
        if(n == nullptr) return;
        if( isEmpty() ) root = n;
        else insertRecur(root, n);
    }
    void remove(int key){
        if(isEmpty()) return; 
        BinaryNode *parent = nullptr; // 없앨 노드의 부모
        BinaryNode *node = root; // 없앨 노드
        while(node!=nullptr&&node->getData()!=key){
            parent = node;
            node = (key<node->getData()) ? node->getLeft() : node->getRight();
        }
        if(node==nullptr){ // 없앨 노드가 트리에 존재하지 않음
            printf(" Error : key is not in the tree!\n ");
            return;
        }
        else remove(parent, node); //없앨 노드가 트리에 존재
    }
private :
    BinaryNode* searchRecur(BinaryNode *n, int key){ 
        if(n == nullptr){return nullptr;}
        if(key == n->getData()){return n;}
        else if(key<n->getData()){return searchRecur(n->getLeft(),key);}
        else{return searchRecur(n->getRight(),key);}
    }
    BinaryNode* searchIter(BinaryNode *n, int key){
        while(n!=nullptr){
            if(key == n->getData()){return n;}
            else if(key < n->getData()){n=n->getLeft();}
            else{n=n->getRight();}
        }
        return nullptr;
    }
    void insertRecur(BinaryNode* r, BinaryNode* n){
        if(n->getData() == r->getData()){ return; }
        else if(n->getData() < r->getData()){
            if(r->getLeft()==nullptr){ r->setLeft(n); }
            else { insertRecur(r->getLeft(), n); }
        }
        else {
            if(r->getRight()==nullptr){ r->setRight(n); }
            else { insertRecur(r->getRight(), n); }
        }
    }
    void remove(BinaryNode* parent, BinaryNode *node){
        // case 1: 삭제하려는 노드가 단말 노드
        if(node->isLeaf()){
            if(parent == nullptr){ root = nullptr; }
            else{
                if(parent->getLeft() == node){parent->setLeft(nullptr);}
                else{parent->setRight(nullptr);}
            }
        }
        // case 2 : 삭제하려는 노드가 좌,우 중 단일 자식 노드만 갖는 경우
        else if(node->getLeft()==nullptr||node->getRight()==nullptr){
            BinaryNode* child = (node->getLeft()!=nullptr) ? node->getLeft() : node->getRight();
            if(node==root){ root = child; }
            else{
                if(parent->getLeft()==node){parent->setLeft(child);}
                else{parent->setRight(child);}
            }
        }
        // case 3 : 삭제하려는 노드가 두개의 자식이 모두 있는 경우
        else{
            //삭제하려는 노드의 오른쪽 서브트리에서 가장 작은 노드를 탐색
            // succ -> 후계노드
            // succp -> 후계노드의 부모노드
            BinaryNode* succp = node;
            BinaryNode* succ = node->getRight();
            while(succ->getLeft()!=nullptr){
                succp = succ;
                succ = succ->getLeft();
            }
            if(succp->getLeft()==succ){succp->setLeft(succ->getRight());}// 후계 노드의 부모와 후계 노드의 오른쪽 자식을 직접 연결
            else{succp->setRight(succ->getRight());}  // 후계 노드가 삭제할 노드의 바로 오른쪽 자식인 경우
            node->setData(succ->getData());
            node = succ;
        }
        delete node;
    }
};