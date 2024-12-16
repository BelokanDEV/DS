#pragma once
#include <stdio.h>

class BinaryNode
{
protected:
	int			data;
	BinaryNode	*left;
	BinaryNode	*right;
public:
	BinaryNode( int val=0, BinaryNode *l=NULL, BinaryNode *r=NULL)
			: data(val), left(l), right(r) { }
	~BinaryNode()	{ }

	void		setData ( int val )		{ data	= val; }
	void		setLeft (BinaryNode *l)	{ left	= l; }
	void		setRight(BinaryNode *r)	{ right	= r; }
	int			getData ()				{ return data; }	
	BinaryNode*	getLeft ()				{ return left; }	
	BinaryNode*	getRight()				{ return right; }	
	bool		isLeaf()	{ return left==NULL && right==NULL; }

	// 트리의 순회
	void inorder() {
		if (left != NULL) left->inorder();
		printf(" [%2d]", data);
		if (right!= NULL) right->inorder();
	}
	void preorder() {
		printf(" [%2d]", data);
		if (left != NULL) left->preorder();
		if (right != NULL) right->preorder();
	}
	void postorder() {
		if (left != NULL) left->postorder();
		if (right != NULL) right->postorder();
		printf(" [%2d]", data);
	}

	int getCount() {
		int count = 1;
		if (left != NULL) count += left->getCount();
		if (right!= NULL) count += right->getCount();
		return count;
	}
	int getLeafCount() {
		if (isLeaf()) return 1;
		int count = 0;
		if (left != NULL) count += left->getLeafCount();
		if (right != NULL) count += right->getLeafCount();
		return count;
	}
	int getHeight() {
		if (isLeaf()) return 1;
		int	hLeft = 0, hRight = 0;

		if (left != NULL) hLeft = left->getHeight();
		if (right!= NULL) hRight= right->getHeight();

		return (hLeft>hRight) ? hLeft + 1 : hRight + 1;
	}


	BinaryNode* search(int key) {
		if (key == data)
			return this;

		else if (key < data && left != NULL)
			return left->search(key);
		else if (key > data && right != NULL)
			return right->search(key);
		return NULL;
	}

	void insert(BinaryNode* n) {
		if (data == n->data) return;

		else if (n->data < data) {
			if (left == NULL) left = n;
			else left->insert(n);
		}
		else if (n->data > data) {
			if (right== NULL) right= n;
			else right->insert(n);
		}
	}
};

