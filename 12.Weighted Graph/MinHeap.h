#pragma once
#include <iostream>
#define MAX_ELEMENT 200

class HeapNode {
    int key;
    int v1;
    int v2;
public:
    HeapNode() : key(0), v1(0), v2(0) { }
    HeapNode(int k, int u, int v) : key(k), v1(u), v2(v) { }

    void setKey(int k) { key = k; }
    void setKey(int k, int u, int v) { key = k; v1 = u; v2 = v; }

    int getKey() { return key; }
    int getV1() { return v1; }
    int getV2() { return v2; }
};

class MinHeap {
    HeapNode node[MAX_ELEMENT];
    int size;

public:
    MinHeap() : size(0) { }

    bool isEmpty() { return size == 0; }
    bool isFull() { return size == MAX_ELEMENT - 1; }

    HeapNode& getParent(int i) { return node[i / 2]; }
    HeapNode& getLeft(int i) { return node[i * 2]; }
    HeapNode& getRight(int i) { return node[i * 2 + 1]; }

    void insert(int key, int u, int v) {
        if (isFull()) return;
        int i = ++size;
        while (i != 1 && key < getParent(i).getKey()) {
            node[i] = getParent(i);
            i /= 2;
        }
        node[i].setKey(key, u, v);
    }

    HeapNode remove() {
        if (isEmpty()) {
            // 빈 힙일 경우 기본 HeapNode 반환
            return HeapNode();
        }

        HeapNode root = node[1];
        HeapNode last = node[size--];

        int parent = 1;
        int child = 2;

        while (child <= size) {
            // 왼쪽 자식과 오른쪽 자식 중 더 작은 자식 선택
            if (child < size && getLeft(parent).getKey() > getRight(parent).getKey())
                child++;

            // 마지막 노드가 자식보다 작거나 같으면 힙 조건 만족
            if (last.getKey() <= node[child].getKey()) break;

            node[parent] = node[child];
            parent = child;
            child *= 2;
        }

        node[parent] = last;
        return root;
    }
};
