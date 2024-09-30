#include <cstdio>
#define MAX_DEGREE 100


//다항식 클래스
class Polynomial{
    private :
    int degree; //차수
    float coef[MAX_DEGREE]; //계수

    public :
        Polynomial() { degree = 0; }
        ~Polynomial(){}

        void read(){
            printf("다항식의 최고 차수를 입력하세요 : ");
            scanf("%d", &degree);
            printf("각 항의 계수를 입력하세요 (총 %d개) : ",degree+1);
            for (int i = degree ; i>=0 ; i--){
                 scanf("%f", &coef[i]);
            }
        }

        void add(Polynomial p1, Polynomial p2){
            if (p1.degree >= p2.degree){
                *this = p1; //현 객체에 p1의 멤버 변수 값을 복사
                for (int i = p2.degree ; i>=0 ; i--){
                    coef[i] += p2.coef[i];
                }
            }
            else{
                *this = p2;
                for (int i = p1.degree ; i>= 0 ; i--){
                    coef[i] += p1.coef[i];
                }
            }
        }

        void mult(Polynomial p1, Polynomial p2){
            if (p1.degree >= p2.degree){
                *this = p1;
                for (int i = p2.degree ; i>=0 ; i--){
                    coef[i] *= p2.coef[i];
                }
            }
            else{
                *this = p2;
                for (int i = p1.degree ; i>= 0 ; i--){
                    coef[i] *= p1.coef[i];
                }
            }
        }
        bool isZero() { return degree == 0; }

        void negate (){
            for (int i = degree; i >= 0; i--){
                coef[i] = -coef[i];
            }
        }
        void display(char *str = " Poly = "){
            printf("\t%s",str);
            for(int i = degree ; i > 0 ; i--){
                printf("%5.1fX^%d ", coef[i], i);
            }
            printf("%5.1f\n", coef[0]);
        }
};

int main (void){
    Polynomial p1, p2, p3;
    p1.read();
    p2.read();

    p3.add(p1, p2);
    p3.display();

    p3.mult(p1,p2);
    p3.display();

    return 0;
}