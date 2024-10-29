#include <cstdio>
#define MAX_SIZE_ARRAY 100
struct Term{
    int expo;
    float coef;
    Term()
    : expo(0), coef(0){}
};
class SparsePoly{
    Term term[MAX_SIZE_ARRAY];
    int nterms;
public :
    SparsePoly()
    : nterms(0) {}
    void read(){
        printf("항의 개수 입력 : \n");
        scanf("%d",&nterms);
        printf("계수와 지수 입력,%d개 입력(EX 5x^2 -> 5 2) : \n",nterms);
        for(int i = 0; i<nterms; i++){
            scanf("%f %d",&term[i].coef, &term[i].expo);
        }
    }
    void add(SparsePoly a, SparsePoly b){
        int i,j;
        nterms = 0;
        for(i = j = 0; i<a.nterms||i<b.nterms;){
            if(i==a.nterms||a.term[i].expo<b.term[j].expo)
                term[nterms++] = b.term[j++];
            if(j==b.nterms||a.term[i].expo>b.term[j].expo)
                term[nterms++] = a.term[i++];
            else{
                term[nterms] = a.term[i++];
                term[nterms++].coef += b.term[j++].coef;
            }
        }
    }
    void display(char* str = "SPoly = "){
        printf("%s ",str);
        for(int i = 0; i<nterms; i++){
            printf("%fx^%d + ",term[i].coef,term[i].expo);
        }
    }
};

int main (void){
    SparsePoly a, b, c;
    a.read();
    b.read();
    
    c.add(a,b);
    c.display("Poly C = ");
    return 0;
}