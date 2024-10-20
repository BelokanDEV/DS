#include "ArrayList.h"

int maxInt(ArrayList a){
    int tmp = 0;
    if (a.size() == 1) { return a[0]; }
    else if(a.getEntry(0) > a.getEntry(1)) {
        tmp = a.getEntry(0);
        a.remove(0);
        return maxInt(a);
    }
    else if(a.getEntry(0) < a.getEntry(1)) {
        tmp = a.getEntry(1);
        a.remove(1);
        return maxInt(a);
    }
}

int main(void){
    ArrayList a;
    a.insert(0, 2);
    a.insert(1, 5);
    a.insert(2, 3);
    a.insert(3, 1);
    maxInt(a);

    return 0;
}