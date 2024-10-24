#include "LinkedStack.h"

class Maze {
    int width; // 미로의 너비
    int height; // 미로의 높이
    int** map; // 미로의 맵 전역을 2차원 배열 동적할당으로 구현
    Location2D* entryLoc; // 미로 입구 위치
    Location2D* exitLoc;  // 미로 출구 위치
    Location2D* tempLoc;  // 미로 현재 위치
public:
    Maze() {
        entryLoc = new Location2D;
        exitLoc = new Location2D;
        tempLoc = new Location2D;
        init(0, 0);
    }

    ~Maze() {
        reset();
        delete entryLoc; 
        delete exitLoc;
        delete tempLoc;
    }

    void init(int w, int h) // 맵 전역 (가로, 세로) 형태로 2차원 배열 동적 할당
    {
        width = w;
        height = h;
        map = new int*[height];
        for (int i = 0; i < height; i++) {
            map[i] = new int[width];
        }
    }

    void reset() { // 미로 맵 Maze 동적 할당 해제
        for (int i = 0; i < height; i++) {
            delete[] map[i];
        }
        delete[] map;   
    }

    void load(char* fname) {
        int w, h;
        FILE* fp = fopen(fname, "r");
        if (fp == NULL) {
            printf("파일을 열 수 없습니다: %s\n", fname);
            return;
        }
        fscanf(fp, "%d", &w);
        fscanf(fp, "%d", &h);
        init(w, h);
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                fscanf(fp, "%d", &map[i][j]);
                if (map[i][j] == 5) {
                    entryLoc->setLoc(i, j);
                }
                if (map[i][j] == 9) {
                    exitLoc->setLoc(i, j);
                }
            }
        }
    }

    // 맵 정보 : 0(벽), 1(길), 2(지나온 경로), 3(최적화 경로), 4(교차로), 5(입구), 9(출구)
    void print() {
        printf("[ 전체 미로의 크기 = %d x %d ]\n", width, height);
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (map[i][j] == 0) { printf("■ "); }
                else if (map[i][j] == 1) { printf("  "); }
                else if (map[i][j] == 2) { printf("□ "); }
                else if (map[i][j] == 5) { printf("○ "); }
                else if (map[i][j] == 9) { printf("◎ "); }
            }
            printf("\n");
        }
    }

    bool isValidLoc(int r, int c) {
        if (r < 0 || c < 0 || r >= height || c >= width) { return false; }
        else { return map[r][c] == 1 || map[r][c] == 9; }
    }

    void searchExit() {
        LinkedStack S;
        S.push(entryLoc);
        int count = 0;
        while (S.isEmpty() == false) {
            int r, c;
            tempLoc = S.pop();
            r = tempLoc->getRow();
            c = tempLoc->getCol();
            if (map[r][c] == 9) {
                printf("미로 탐색 성공!!\n");
                return;
            }
            else {
                map[r][c] = 2; // 지나간 경로를 표시
                count = 0;
                if (isValidLoc(r - 1, c)) {
                    S.push(new Location2D(r - 1, c)); 
                }
                if (isValidLoc(r + 1, c)) {
                    S.push(new Location2D(r + 1, c)); 
                }
                if (isValidLoc(r, c - 1)) {
                    S.push(new Location2D(r, c - 1)); 
                }
                if (isValidLoc(r, c + 1)) {
                    S.push(new Location2D(r, c + 1)); 
                }
            }
        }
        printf("미로 탐색 실패\n");
    }
};
