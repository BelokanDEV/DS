#pragma once
#include "BinaryNode.h"

// BinaryTree Ŭ���� ����: ���� Ʈ���� ǥ���ϰ� �����ϴ� �پ��� �޼��� ����
class BinaryTree {
    BinaryNode* root; // Ʈ���� ��Ʈ ��带 ����Ű�� ������

public:
    // ������: Ʈ���� ��� �ִ� ���·� �ʱ�ȭ
    BinaryTree() : root(NULL) { }

    // �Ҹ���: �������� �Ҵ�� ��带 �����ϴ� �ڵ尡 �ʿ��� �� ����
    ~BinaryTree() { }

    // ��Ʈ ��带 ����
    void setRoot(BinaryNode* node) { root = node; }

    // ��Ʈ ��带 ��ȯ
    BinaryNode* getRoot() { return root; }

    // Ʈ���� ��� �ִ��� Ȯ��
    bool isEmpty() { return root == NULL; }

    // Ʈ���� ��ü ��� ������ ��ȯ
    int getCount() { return isEmpty() ? 0 : getCount(root); }

    // ���� ���(�ڽ��� ���� ���) ������ ��ȯ
    int getLeafCount() { return isEmpty() ? 0 : getLeafCount(root); }

    // Ʈ���� ���̸� ��ȯ (��Ʈ���� ���� ���� �������� �Ÿ�)
    int getHeight() { return isEmpty() ? 0 : getHeight(root); }

    // ���� ��ȸ(Preorder Traversal): ��Ʈ -> ���� -> ������ ������ ��带 �湮
    void preorder(BinaryNode* node) {
        if (node != NULL) {
            printf(" [%c] ", node->getData()); // ���� ����� �����͸� ���
            if (node->getLeft() != NULL) preorder(node->getLeft()); // ���� ����Ʈ�� �湮
            if (node->getRight() != NULL) preorder(node->getRight()); // ������ ����Ʈ�� �湮
        }
    }

    // ��Ʈ���� �����Ͽ� Ʈ���� ���� ��ȸ ����� ���
    void preorder() {
        printf("\n  preorder: ");
        preorder(root);
        printf("\n");
    }

    // Ʈ���� ��� ��� ������ ��������� ���
    int getCount(BinaryNode* node) {
        if (node == NULL) return 0;
        return 1 + getCount(node->getLeft()) + getCount(node->getRight());
    }

    // ���� ����� ������ ��������� ���
    int getLeafCount(BinaryNode* node) {
        if (node == NULL) return 0;
        if (node->isLeaf()) return 1; // ���� ����̸� 1 ��ȯ
        else return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
    }

    // Ʈ���� ���̸� ��������� ���
    int getHeight(BinaryNode* node) {
        if (node == NULL) return 0;
        int hLeft = getHeight(node->getLeft()); // ���� ����Ʈ���� ����
        int hRight = getHeight(node->getRight()); // ������ ����Ʈ���� ����
        return (hLeft > hRight) ? hLeft + 1 : hRight + 1; // �� ū ���̿� 1�� �߰�
    }

    // Ʈ���� ��� ��� ������ ���� �ջ��Ͽ� ��ȯ
    int calcSize() { return calcSize(root); }

    // ��������� ��� ������ �� �ջ�
    int calcSize(BinaryNode* node) {
        if (node == NULL) return 0;
        return node->getData() + calcSize(node->getLeft()) + calcSize(node->getRight());
    }

    // ���� Ʈ������ ���� ����� ���
    int evaluate() { return evaluate(root); }

    // ��������� ���� Ʈ���� ���� ���
    int evaluate(BinaryNode* node) {
        if (node == NULL) return 0;
        if (node->isLeaf()) return node->getData(); // ���� ����� ���� ��ȯ
        else {
            int op1 = evaluate(node->getLeft()); // ���� ����Ʈ���� ��
            int op2 = evaluate(node->getRight()); // ������ ����Ʈ���� ��
            switch (node->getData()) { // �����ڿ� ���� ��� ����
            case '+': return op1 + op2;
            case '-': return op1 - op2;
            case '*': return op1 * op2;
            case '/': return op1 / op2;
            }
            return 0; // ���� ó��
        }
    }

    //================================================================
    // ��� ��尡 �ڽ� ��带 �� ���� ������ �ִ��� Ȯ�� (���� ���� Ʈ�� ����)
    bool isEven(TNode* n) {
        if ((n == NULL) || (n->left == NULL && n->right == NULL)) return true;
        if (n->left == NULL || n->right == NULL) return false;
        return isEven(n->left) && isEven(n->right);
    }

    // Ʈ���� ���� ���� Ʈ������ Ȯ��
    bool isFull() {
        bool ret = isEven(root);
        printf("Ʈ���� %s\n", ret ? "���� ���� Ʈ���Դϴ�." : "���� ���� Ʈ���� �ƴմϴ�.");
        return ret;
    }

    //================================================================
    // Ư�� ����� ����(����)�� Ȯ��
    int checkLevel(TNode* p, TNode* n, int level) {
        int ll = 0, lr = 0;
        if (p == n) return level; // ���� ��尡 ��ǥ ����� ���� ��ȯ
        if (p->left != NULL) ll = checkLevel(p->left, n, level + 1);
        if (p->right != NULL) lr = checkLevel(p->right, n, level + 1);
        return (ll > 0) ? ll : lr; // ��ǥ ��尡 �߰ߵ� ���� ��ȯ
    }

    // ��Ʈ���� Ư�� �������� ���� ��ȯ
    int calcLevel(TNode* n) {
        int level = 0;
        if (root != NULL) level = checkLevel(root, n, 1);
        printf("%s\n", (level > 0) ? "����� ������ Ȯ���߽��ϴ�." : "Ʈ���� �ش� ��尡 �������� �ʽ��ϴ�.");
        return level;
    }

    //================================================================
    // Ʈ���� ���� ���� Ʈ������ Ȯ��
    bool checkBalanced(TNode* p) {
        if (p == NULL) return true;
        int lh = getHeight(p->left);
        int rh = getHeight(p->right);
        int dh = rh - lh;
        if (dh < -1 || dh > 1) return false; // ���� ���� 1 �̻��̸� �ұ���
        if (!checkBalanced(p->left)) return false;
        return checkBalanced(p->right);
    }

    // Ʈ���� ���� ���� Ʈ������ ���� ��ȯ
    bool isBalanced() {
        bool ret = checkBalanced(root);
        printf("Ʈ���� %s\n", ret ? "���� ���� Ʈ���Դϴ�." : "�ұ��� Ʈ���Դϴ�.");
        return ret;
    }

    //================================================================
    // ��Ʈ���� ��� �������� ��� ���� �ջ�
    int calcPathLength(TNode* p, int level) {
        if (p == NULL) return 0;
        int llen = calcPathLength(p->left, level + 1);
        int rlen = calcPathLength(p->right, level + 1);
        return llen + rlen + level;
    }

    // Ʈ���� �� ��� ���� ��ȯ
    int pathLength() {
        int len = calcPathLength(root, 0);
        printf("��ü ��� ���̴� %d�Դϴ�.\n", len);
        return len;
    }

    //================================================================
    // Ʈ���� ���ʰ� ������ ��带 ��ȯ
    void swapNodes(TNode* p) {
        if (p == NULL) return;
        TNode* tmp = p->left;
        p->left = p->right;
        p->right = tmp;
        swapNodes(p->left);
        swapNodes(p->right);
    }

    // Ʈ�� ��ü�� �¿� ����
    void reverse() {
        printf("\nƮ���� �¿� �����մϴ�.");
        swapNodes(root);
    }

    //================================================================
    // �� ����Ʈ���� ���� ��带 �������� Ȯ��
    int hasSameNode(TNode* p, TNode* n) {
        if (n == NULL || p == NULL) return 0;
        if (n == p) return 1;
        return hasSameNode(p->left, n) + hasSameNode(p->right, n);
    }

    // �� ����Ʈ���� ���� ���������� Ȯ��
    int isDisjointFrom(TNode* p, TNode* n) {
        if (p == NULL || n == NULL) return 1;
        if (hasSameNode(p, n)) return 0;
        if (hasSameNode(p, n->left)) return 0;
        if (hasSameNode(p, n->right)) return 0;
        return 1;
    }

    // Ʈ���� ��ȿ���� Ȯ��
    int checkValid(TNode* n) {
        if (n == NULL) return 1;
        if (!isDisjointFrom(n->left, n->right)) return 0;
        if (!checkValid(n->left)) return 0;
        if (!checkValid(n->right)) return 0;
        return 1;
    }

    // Ʈ���� ��ȿ�� ���� ��ȯ
    int isValid() {
        int ret = checkValid(root);
        printf("Ʈ���� %s\n", ret ? "��ȿ�մϴ�." : "��ȿ���� �ʽ��ϴ�.");
        return ret;
    }
};
