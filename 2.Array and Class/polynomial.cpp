#include "polynomial.h"
int main (void)
{
    Polynomial a,b,c;
    a.read();
    b.read();
    c.add (a, b);
    a.display("A = ");
    b.display("B = ");
    c.display("A+B = ");
}
