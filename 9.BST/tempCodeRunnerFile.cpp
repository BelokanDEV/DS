#include "BinSrchTree.h"
int main(){
    BinSrchTree tree;

    tree.insert( new BinaryNode(35) );
    tree.insert( new BinaryNode(18) );
    tree.insert( new BinaryNode(7) );
    tree.insert( new BinaryNode(26) );
    tree.insert( new BinaryNode(12) );
    tree.insert( new BinaryNode(3) );
    tree.insert( new BinaryNode(68) );
    tree.insert( new BinaryNode(22) );
    tree.insert( new BinaryNode(30) );
    tree.insert( new BinaryNode(99) );

    printf(" 노드의 개수 = %d\n", tree.getCount());
    printf(" 단말의 개수 = %d\n", tree.getLeafCount());
    printf(" 트리의 높이 = %d\n", tree.getHeight());

    tree.inorder();
    tree.preorder();
    tree.postorder();

    //노드 탐색
    tree.search(26);
    tree.search(25);

    //삭제 연산
    printf("case 1 ==> 노드 3 삭제\n");
    tree.remove(3);
    tree.inorder();
    printf("case 2 ==> 노드 68 삭제\n");
    tree.remove(68);
    tree.inorder();
    printf("case 3 ==> 노드 18 삭제\n");
    tree.remove(18);
    tree.inorder();
    printf("case 3 ==> 노드 35 삭제(루트 노드 삭제)\n");
    tree.remove(35);
    tree.inorder();

    printf(" 노드의 개수 = %d\n", tree.getCount());
    printf(" 단말의 개수 = %d\n", tree.getLeafCount());
    printf(" 트리의 높이 = %d\n", tree.getHeight());
    
    return 0;
}