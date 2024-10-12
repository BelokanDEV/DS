#include <cstdio>
#include <cstdlib>
#define MAX_LIST_SIZE 100

inline void error(char* str) {
    printf("ERROR: %s\n", str);
    exit(1);
}

class ArrayList {
    int data[MAX_LIST_SIZE];
    int length;

public:
    ArrayList() : length(0) {}
    ~ArrayList() {}

    bool isFull() { return length == MAX_LIST_SIZE; }
    bool isEmpty() { return length == 0; }

    void insert(int pos, int item) {
        if (isFull()) { error("List is FULL!"); }
        if (pos < 0 || pos > length) { error("Invalid Position!"); }

        for (int i = length - 1; i >= pos; i--) {
            data[i + 1] = data[i];
        }
        data[pos] = item;
        length++;
    }

    void remove(int pos) {
        if (isEmpty()) { error("List is EMPTY!"); }
        if (pos < 0 || pos >= length) { error("Invalid Position!"); }

        for (int i = pos; i < length - 1; i++) {
            data[i] = data[i + 1];
        }
        length--;
    }

    int getEntry(int pos) {
        if (pos < 0 || pos >= length) { error("Invalid Position!"); }
        return data[pos];
    }

    bool find(int item) {
        for (int i = 0; i < length; i++) {
            if (data[i] == item) {
                return true;
            }
        }
        return false;
    }

    void replace(int pos, int item) {
        if (pos < 0 || pos >= length) { error("Invalid Position!"); }
        data[pos] = item;
    }

    int size() { return length; }

    void display() {
        printf("[배열로 구현한 리스트 전체 항목 수 = %2d] : ", size());
        for (int i = 0; i < length; i++) {
            printf("[%2d] ", data[i]);
        }
        printf("\n");
    }
    void clear() { length = 0;}
};
