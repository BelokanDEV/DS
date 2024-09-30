#include <iostream>
class Rectangle
        {
            int w; //가로
            int h; //세로
            public :
                Rectangle(int width, int height)
                {
                    w = width;
                    h = height;
                }
                int area() //사각형의 넓이
                {
                    return w * h;
                }
                int perimeter()//사각형의 둘레
                {
                    return 2 * w + 2 * h;
                }
        };

int main()
{
    using namespace std; 
    Rectangle r(1,2);
    cout << "Area : " << r.area() << endl;
    cout << "Perimeter : " << r.perimeter() << endl;
    return 0;
}

