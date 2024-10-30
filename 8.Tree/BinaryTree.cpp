#include "BinaryTree.h"
int main(){
    BinaryTree tree;
    BinaryNode* d = new BinaryNode('D', nullptr, nullptr);
    BinaryNode* e = new BinaryNode('E', nullptr, nullptr);
    BinaryNode* b = new BinaryNode('B', d, e);
    BinaryNode* f = new BinaryNode('F', nullptr, nullptr);
    BinaryNode* c = new BinaryNode('C', f, nullptr);
    BinaryNode* a = new BinaryNode('A', b,c);
    tree.setRoot(a);

    // 순회
    // tree.inorder();
    // tree.preorder();
    // tree.postorder();
    // tree.levelorder();

    // 트리의 연산
    // printf("Node Count : %d\n",tree.getCount());
    // printf("Leaf-Node Count : %d\n",tree.getLeafCount());
    // printf("Height : %d\n",tree.getHeight());

    // 수식 트리 (후위 계산)
    // BinaryTree tree2;
    // BinaryNode *n1 = new BinaryNode(3, nullptr, nullptr);
    // BinaryNode *n2 = new BinaryNode(2, nullptr, nullptr);
    // BinaryNode *n3 = new BinaryNode('*', n1, n2);
    // BinaryNode *n4 = new BinaryNode(5, nullptr, nullptr);
    // BinaryNode *n5 = new BinaryNode(6, nullptr, nullptr);
    // BinaryNode *n6 = new BinaryNode('-', n4, n5);
    // BinaryNode *n7 = new BinaryNode('+', n3, n6);
    // tree2.setRoot(n7);
    // printf(" 계산결과 = %d\n",tree2.evaluate());

    
    return 0;
}