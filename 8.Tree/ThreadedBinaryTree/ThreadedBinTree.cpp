#include "ThreadedBinaryTree.h"

int main(){
    ThreadedBinTree tree;
    //          G
    //      C       F
    //  A       B   D   E
    ThreadedBinNode* n1 = new ThreadedBinNode('A', nullptr, nullptr, true);
    ThreadedBinNode* n2 = new ThreadedBinNode('B', nullptr, nullptr, true);
    ThreadedBinNode* n3 = new ThreadedBinNode('C', n1, n2, false);
    ThreadedBinNode* n4 = new ThreadedBinNode('D', nullptr, nullptr, true);
    ThreadedBinNode* n5 = new ThreadedBinNode('E', nullptr, nullptr, true);
    ThreadedBinNode* n6 = new ThreadedBinNode('F', n4, n5, false);
    ThreadedBinNode* n7 = new ThreadedBinNode('G', n3, n6, false);
    tree.setRoot(n7);

    n1->setRight(n3);
    n2->setRight(n7);
    n4->setRight(n6);

    tree.threadedInorder();
    return 0;
}