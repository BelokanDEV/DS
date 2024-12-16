#pragma once
#include "BinaryNode.h"

// BinaryTree 클래스 정의: 이진 트리를 표현하고 조작하는 다양한 메서드 포함
class BinaryTree {
    BinaryNode* root; // 트리의 루트 노드를 가리키는 포인터

public:
    // 생성자: 트리를 비어 있는 상태로 초기화
    BinaryTree() : root(NULL) { }

    // 소멸자: 동적으로 할당된 노드를 삭제하는 코드가 필요할 수 있음
    ~BinaryTree() { }

    // 루트 노드를 설정
    void setRoot(BinaryNode* node) { root = node; }

    // 루트 노드를 반환
    BinaryNode* getRoot() { return root; }

    // 트리가 비어 있는지 확인
    bool isEmpty() { return root == NULL; }

    // 트리의 전체 노드 개수를 반환
    int getCount() { return isEmpty() ? 0 : getCount(root); }

    // 리프 노드(자식이 없는 노드) 개수를 반환
    int getLeafCount() { return isEmpty() ? 0 : getLeafCount(root); }

    // 트리의 높이를 반환 (루트부터 가장 깊은 노드까지의 거리)
    int getHeight() { return isEmpty() ? 0 : getHeight(root); }

    // 전위 순회(Preorder Traversal): 루트 -> 왼쪽 -> 오른쪽 순으로 노드를 방문
    void preorder(BinaryNode* node) {
        if (node != NULL) {
            printf(" [%c] ", node->getData()); // 현재 노드의 데이터를 출력
            if (node->getLeft() != NULL) preorder(node->getLeft()); // 왼쪽 서브트리 방문
            if (node->getRight() != NULL) preorder(node->getRight()); // 오른쪽 서브트리 방문
        }
    }

    // 루트부터 시작하여 트리의 전위 순회 결과를 출력
    void preorder() {
        printf("\n  preorder: ");
        preorder(root);
        printf("\n");
    }

    // 트리의 모든 노드 개수를 재귀적으로 계산
    int getCount(BinaryNode* node) {
        if (node == NULL) return 0;
        return 1 + getCount(node->getLeft()) + getCount(node->getRight());
    }

    // 리프 노드의 개수를 재귀적으로 계산
    int getLeafCount(BinaryNode* node) {
        if (node == NULL) return 0;
        if (node->isLeaf()) return 1; // 리프 노드이면 1 반환
        else return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
    }

    // 트리의 높이를 재귀적으로 계산
    int getHeight(BinaryNode* node) {
        if (node == NULL) return 0;
        int hLeft = getHeight(node->getLeft()); // 왼쪽 서브트리의 높이
        int hRight = getHeight(node->getRight()); // 오른쪽 서브트리의 높이
        return (hLeft > hRight) ? hLeft + 1 : hRight + 1; // 더 큰 높이에 1을 추가
    }

    // 트리의 모든 노드 데이터 값을 합산하여 반환
    int calcSize() { return calcSize(root); }

    // 재귀적으로 노드 데이터 값 합산
    int calcSize(BinaryNode* node) {
        if (node == NULL) return 0;
        return node->getData() + calcSize(node->getLeft()) + calcSize(node->getRight());
    }

    // 수식 트리에서 연산 결과를 계산
    int evaluate() { return evaluate(root); }

    // 재귀적으로 수식 트리의 값을 계산
    int evaluate(BinaryNode* node) {
        if (node == NULL) return 0;
        if (node->isLeaf()) return node->getData(); // 리프 노드라면 값을 반환
        else {
            int op1 = evaluate(node->getLeft()); // 왼쪽 서브트리의 값
            int op2 = evaluate(node->getRight()); // 오른쪽 서브트리의 값
            switch (node->getData()) { // 연산자에 따라 계산 수행
            case '+': return op1 + op2;
            case '-': return op1 - op2;
            case '*': return op1 * op2;
            case '/': return op1 / op2;
            }
            return 0; // 예외 처리
        }
    }

    //================================================================
    // 모든 노드가 자식 노드를 두 개씩 가지고 있는지 확인 (완전 이진 트리 여부)
    bool isEven(TNode* n) {
        if ((n == NULL) || (n->left == NULL && n->right == NULL)) return true;
        if (n->left == NULL || n->right == NULL) return false;
        return isEven(n->left) && isEven(n->right);
    }

    // 트리가 완전 이진 트리인지 확인
    bool isFull() {
        bool ret = isEven(root);
        printf("트리가 %s\n", ret ? "완전 이진 트리입니다." : "완전 이진 트리가 아닙니다.");
        return ret;
    }

    //================================================================
    // 특정 노드의 레벨(깊이)을 확인
    int checkLevel(TNode* p, TNode* n, int level) {
        int ll = 0, lr = 0;
        if (p == n) return level; // 현재 노드가 목표 노드라면 레벨 반환
        if (p->left != NULL) ll = checkLevel(p->left, n, level + 1);
        if (p->right != NULL) lr = checkLevel(p->right, n, level + 1);
        return (ll > 0) ? ll : lr; // 목표 노드가 발견된 레벨 반환
    }

    // 루트부터 특정 노드까지의 레벨 반환
    int calcLevel(TNode* n) {
        int level = 0;
        if (root != NULL) level = checkLevel(root, n, 1);
        printf("%s\n", (level > 0) ? "노드의 레벨을 확인했습니다." : "트리에 해당 노드가 존재하지 않습니다.");
        return level;
    }

    //================================================================
    // 트리가 균형 잡힌 트리인지 확인
    bool checkBalanced(TNode* p) {
        if (p == NULL) return true;
        int lh = getHeight(p->left);
        int rh = getHeight(p->right);
        int dh = rh - lh;
        if (dh < -1 || dh > 1) return false; // 높이 차가 1 이상이면 불균형
        if (!checkBalanced(p->left)) return false;
        return checkBalanced(p->right);
    }

    // 트리가 균형 잡힌 트리인지 여부 반환
    bool isBalanced() {
        bool ret = checkBalanced(root);
        printf("트리가 %s\n", ret ? "균형 잡힌 트리입니다." : "불균형 트리입니다.");
        return ret;
    }

    //================================================================
    // 루트에서 모든 노드까지의 경로 길이 합산
    int calcPathLength(TNode* p, int level) {
        if (p == NULL) return 0;
        int llen = calcPathLength(p->left, level + 1);
        int rlen = calcPathLength(p->right, level + 1);
        return llen + rlen + level;
    }

    // 트리의 총 경로 길이 반환
    int pathLength() {
        int len = calcPathLength(root, 0);
        printf("전체 경로 길이는 %d입니다.\n", len);
        return len;
    }

    //================================================================
    // 트리의 왼쪽과 오른쪽 노드를 교환
    void swapNodes(TNode* p) {
        if (p == NULL) return;
        TNode* tmp = p->left;
        p->left = p->right;
        p->right = tmp;
        swapNodes(p->left);
        swapNodes(p->right);
    }

    // 트리 전체를 좌우 반전
    void reverse() {
        printf("\n트리를 좌우 반전합니다.");
        swapNodes(root);
    }

    //================================================================
    // 두 서브트리가 공통 노드를 가지는지 확인
    int hasSameNode(TNode* p, TNode* n) {
        if (n == NULL || p == NULL) return 0;
        if (n == p) return 1;
        return hasSameNode(p->left, n) + hasSameNode(p->right, n);
    }

    // 두 서브트리가 서로 독립적인지 확인
    int isDisjointFrom(TNode* p, TNode* n) {
        if (p == NULL || n == NULL) return 1;
        if (hasSameNode(p, n)) return 0;
        if (hasSameNode(p, n->left)) return 0;
        if (hasSameNode(p, n->right)) return 0;
        return 1;
    }

    // 트리가 유효한지 확인
    int checkValid(TNode* n) {
        if (n == NULL) return 1;
        if (!isDisjointFrom(n->left, n->right)) return 0;
        if (!checkValid(n->left)) return 0;
        if (!checkValid(n->right)) return 0;
        return 1;
    }

    // 트리의 유효성 여부 반환
    int isValid() {
        int ret = checkValid(root);
        printf("트리가 %s\n", ret ? "유효합니다." : "유효하지 않습니다.");
        return ret;
    }
};
