#include <iostream>

class Rectangle {
    private :
    int wide, height;
    public :
    Rectangle(int w, int h){
        wide = w;
        height = h;
    }
    ~Rectangle(){}
    int area(){ return wide * height; }
    int perimeter() { return 2*wide + 2*height; }    
};

int main (void){
    using namespace std;
    Rectangle a(5, 4), b(6, 9);
    cout << a.area() << endl;
    cout << b.area() << endl;
    cout << a.perimeter() << endl;
    cout << b.perimeter() << endl;
    
    return 0;
}