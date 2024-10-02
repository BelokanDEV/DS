#include <cstdio>
#define MAX_DEGREE 100

class Polynomial{
    private :
    int degree;
    float coef[MAX_DEGREE];
    public :
    Polynomial(){};
    ~Polynomial(){};
    void read(){
        printf("최고 차수 입력 : ");
        scanf("%d", &degree);
        printf("\n각 항의 계수 입력(%d 개) : ",degree+1);
        for(int i = degree; i>=0; i--){
            scanf("%f", &coef[i]);
        }
    }
    void add(Polynomial p1, Polynomial p2){
        if (p1.degree >= p2.degree) degree = p1.degree;
        else degree = p2.degree;
        for(int i = degree; i>=0; i--){
            coef[i] = p1.coef[i] + p2.coef[i];
        }
    }

    void negate(){
        for(int i = degree; i>=0; i--){
            coef[i] = -coef[i];
        }
    }
    bool isZero() { return ((degree == 0) && (coef[0] == 0)); }


    void display(){
        for(int i = degree; i>0; i--){
            printf("%5.1fX^%d + ",coef[i], i);
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
    
    return 0;
}