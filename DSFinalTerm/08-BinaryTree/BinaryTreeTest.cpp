#include "BinaryTree.h"
typedef BinaryTree	BinTree;

int main()
{
	BinTree tree, tree2, tree3;
	TNode *a, *b, *c, *d, *e, *f;

	//           A
	//       B       E
	//     C   D        F  
	c = new TNode('C', NULL, NULL);
	d = new TNode('D', NULL, NULL);
	f = new TNode('F', NULL, NULL);
	b = new TNode('B', c, d);
	e = new TNode('E', NULL, f );
	a = new TNode('A', b, e);

	tree.setRoot(a);

	printf(" ��� ���� = %d\n", tree.getCount( ));
	printf(" �ܸ� ���� = %d\n", tree.getLeafCount( ));
	printf(" Ʈ�� ���� = %d\n", tree.getHeight());

	tree.preorder();
	printf("(1)\n");
	tree.isFull();
	printf("(2)\n");
	tree.calcLevel(a);
	tree.calcLevel(b);
	tree.calcLevel(c);
	tree.calcLevel(d);
	tree.calcLevel(e);
	tree.calcLevel(f);

	printf("(3)\n");
	tree.isBalanced();

	printf("(4)\n");
	tree.pathLength();


	printf("(5)");
	tree.reverse();
	tree.preorder();

	printf("(6)\n");
	printf("��Ʈb�� Ʈ���� ��Ʈe�� Ʈ���� Disjoint %s.\n", 
		tree.isDisjointFrom(b, e) ? "�մϴ�" : "���� �ʽ��ϴ�");

	printf("(7)\n");
	tree.isValid();
}