#include <cstdio>
class complex{
    private :
        float real;
        int imag;
    public :
        complex(){}
        ~complex(){}
        complex(float r, int i){
            real = r;
            imag = i;
        }
        void add(complex c1, complex c2){
            real = c1.real + c2.real;
            imag = c1.imag + c2.imag;
        }
        void subt(complex c1, complex c2){
            real = c1.real - c2.real;
            imag = c1.imag - c2.imag;
        }
        void mult(complex c1, complex c2){
            float multSumReal = 0;
            int multSumImag = 0;

            multSumReal += c1.real * c2.real;
            multSumReal += -(c1.imag * c2.imag);

            multSumImag += c1.real * c2.imag;
            multSumImag += c1.imag * c2.real;

            real = multSumReal;
            imag = multSumImag;
        }
        void display(char *str = " Complex = "){
            printf("%s%5.1f + %di\n",str , real, imag);
        }
};
int main (void){
    complex a(3,5), b(6,2);
    complex c;
    c.add(a,b);
    c.display();

    c.mult(a,b);
    c.display();

    c.subt(b,a);
    c.display();

    return 0;
}