#include "Maze.h"
int main(void){
    Maze maze;
    maze.load("maze.txt");
    maze.print();
    maze.searchExit();
    maze.print();
    return 0;
}