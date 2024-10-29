#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE	100

inline void error(char* str) {
	fprintf(stderr, "%s\n", str);
	exit(1);
};

struct Term {				// �ϳ��� ���� ǥ���ϴ�  Ŭ����
	int		expon;			// ���� ����
	float	coeff;			// ���� ���
	Term(int expo = 0, float coef = 0.0f) : expon(expo), coeff(coef) {}
	void print() {
		if (coeff != 0.0f) {
			if (coeff > 0) printf("+");
			printf("%6.2f", coeff);
			if (expon != 0)printf("x^%d ", expon);
		}
	}
};

struct Node
{
	Node*	link;
	Term	data;

	Node(int exp=0, float coe=0.0f) : data(exp,coe), link(NULL) { }

	void display() { data.print(); }

	void insertNext(Node *n) {
		if (n != NULL) {
			n->link = link;
			link = n;
		}
	}

	Node* removeNext() {
		Node* removed = link;
		if (removed != NULL)
			link = removed->link;
		return removed;
	}
};

class LinkedList
{
	Node	org;	// ��� ��� (��� �����Ͱ� �ƴ�)

public:
	LinkedList() : org(0) { }
	~LinkedList() { clear(); }

	void clear() { while (!isEmpty()) delete remove(0); }
	Node* getHead() { return org.link; }
	bool isEmpty() { return getHead() == NULL; }

	Node* getEntry(int pos) {
		Node* n = &org;
		for (int i = -1; i<pos; i++, n = n->link)
			if (n == NULL) break;
		return n;
	}

	void insert(int pos, Node *n) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL)
			prev->insertNext(n);
	}

	Node* remove(int pos) {
		Node* prev = getEntry(pos - 1);
		return prev->removeNext();
	}

	int size() {
		int count = 0;
		for (Node *p = getHead(); p != NULL; p = p->link)
			count++;
		return count;
	}

	void display(const char* str = "���׽�") {
		printf("%s", str);
		printf("[�ܼ����Ḯ��Ʈ �׸� �� = %2d] : ", size());
		for (Node *p = getHead(); p != NULL; p = p->link)
			p->display();
		printf("\n");
	}
};
class SparsePoly : public LinkedList {

public:
	void read() {
		int expo;
		float coef;

		Term	t;
		while (1) {
			printf("��� ���� �Է�(����:-1): ");
			scanf("%f%d", &coef, &expo);
			if (expo < 0) {
				display("�Է� ���׽�:");
				return;
			}
			insert(size(), new Node(expo, coef));
		}
	}

	void add(SparsePoly* a, SparsePoly* b) {
		Node	*i = a->getHead(), *j = b->getHead();
		Term	t;

		for (; i != NULL || j != NULL;) {
			if (i == NULL || ((j != NULL) && (i->data.expon < j->data.expon))) {
				insert(size(), new Node(*j));
				j = j->link;
			}
			else if (j == NULL || ((i != NULL) && i->data.expon > j->data.expon)) {
				insert(size(), new Node(*i));
				i = i->link;
			}
			else {
				t = i->data;
				t.coeff += j->data.coeff;
				insert(size(), new Node(t.expon, t.coeff));
				i = i->link;
				j = j->link;
			}
		}
	}
};
