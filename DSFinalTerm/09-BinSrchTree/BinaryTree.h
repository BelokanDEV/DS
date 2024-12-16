#pragma once
#include "BinaryNode.h"
#include "CircularQueue.h"

class BinaryTree
{
protected:
	BinaryNode*	root;
public:

	BinaryTree(): root(NULL) { }
	~BinaryTree()	{ }

	void setRoot(BinaryNode* node)	{ root = node; }
	BinaryNode* getRoot()			{ return root; }
	bool isEmpty()	{ return root==NULL; }

	int	getCount()	{ return isEmpty() ? 0 : root->getCount(); }
	int	getLeafCount(){ return isEmpty() ? 0 : root->getLeafCount(); }
	int	getHeight()	{ return isEmpty() ? 0 : root->getHeight(); }

	void inorder()	{
		printf("\n   inorder: ");
		if( !isEmpty() ) root->inorder();
		printf("\n");
	}
	void preorder()	{
		printf("\n  preorder: ");
		if (!isEmpty()) root->preorder();
		printf("\n");
	}
	void postorder(){
		printf("\n postorder: ");
		if (!isEmpty()) root->postorder();
		printf("\n");
	}
	void levelorder() {
		printf("\nlevelorder: ");
		if (!isEmpty()) {
			CircularQueue q;
			q.enqueue(root);
			while (!q.isEmpty()) {
				BinaryNode* n = q.dequeue();
				if (n != NULL) {
					printf(" [%2d]", n->getData());
					q.enqueue(n->getLeft());
					q.enqueue(n->getRight());
				}
			}
		}
		printf("\n");
	}

};

