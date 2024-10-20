#include <cstdio>
#define MAX_TERMS 100
struct Term{
    int expo;
    float coef;
};
class SparsePoly{
    int nTerms;
    Term term[MAX_TERMS];
public :
    SparsePoly(){};
    ~SparsePoly(){};

   void read() {
		nTerms = 0;
		while (1) {
			printf("계수 차수 입력(종료:-1): ");
			scanf("%f%d", &(term[nTerms].coef), &(term[nTerms].expo));
			if (term[nTerms].expo < 0) {
				display("입력 다항식:");
				return;
			}
			nTerms++;
		}
	}
    void add(SparsePoly a, SparsePoly b){   
        int i, j;
        nTerms = 0;
        for(i = j = 0; i<a.nTerms || j<b.nTerms;){
            if((i == a.nTerms)||(a.term[i].expo<b.term[j].expo))
            { term[nTerms++] = b.term[j++]; }
            if((j == b.nTerms)||(b.term[j].expo<a.term[i].expo))
            { term[nTerms++] = a.term[j++]; }
            else{
                term[nTerms] = a.term[i++];
                term[nTerms++].coef += b.term[j++].coef;
            }
        }
    }
    void display(char* str= "SPoly = "){
        printf("\t%s",str);
        for(int i = 0; i<=nTerms; i++){
            printf("%5.1f", term[i].coef);
            if(term[i].expo > 0){ 
                printf(" x^%d",term[i].expo);
            }
        }
        printf("\n");
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