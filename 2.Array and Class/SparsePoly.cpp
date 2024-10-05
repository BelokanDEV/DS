#include <cstdio>
#define MAX_TERMS 100

struct Term{
    int expo;
    float coef;
};

class SparsePoly{
    private :
    int nTerms;
    Term term[MAX_TERMS];
    public :

    SparsePoly(){}
    ~SparsePoly(){}

    void read(){
        nTerms = 0;
        printf("다항식의 계수와 지수를 입력하세요! (ex : 10x^5 -> \"10 5\" 입력) \n입력 종료는 \"-1 -1\" 입력\n");
        while (1){
        printf("입력 : ");
        scanf("%f %d", &term[nTerms].coef, &term[nTerms].expo);
        if(term[nTerms].expo == -1 && term[nTerms].coef == -1) { break; }
        nTerms++;
        }

        for(int i= 0; i<nTerms; i++){ // 동차항 덧셈처리
            for(int j = i+1; j<nTerms; ){
                if(term[i].expo == term[j].expo){
                    term[i].coef += term[j].coef;
                    for(int k = j; k<nTerms; k++){
                        term[k] = term[k+1];
                    }
                    nTerms--;
                }
                else{ j++; }
            }
        }
        for(int i = 0; i<nTerms; i++){ //차수에 따른 배열 순서 정렬
            for(int j = i; j<nTerms; j++){
                if (term[i].expo < term[j].expo){
                    int tempExpo = 0;
                    float tempCoef = 0;
                    tempExpo = term[i].expo;
                    term[i].expo = term[j].expo;
                    term[j].expo = tempExpo;
                    tempCoef = term[i].coef;
                    term[i].coef = term[j].coef;
                    term[j].coef = tempCoef;
                }
            }
        }
    }

    void display(char *str = " SparsePoly = "){
        printf("%s", str);
        for(int i = 0; i<nTerms; i++){
            if(term[i].coef == 0){ continue; }
            else if(term[i].expo == 0){
                printf("%5.1f",term[i].coef);
            }
            else if(term[i].coef == 1){
                printf("X^%d",term[i].expo);
            }
            else{
            printf("%5.1fX^%d", term[i].coef, term[i].expo);
            }
            if(i == nTerms-1) { break; }
            else{
                if(term[i].coef >= 0) { printf(" +"); }
                else { printf(" "); }
            }
        }
    }

    void add(SparsePoly a, SparsePoly b){
        nTerms = a.nTerms + b.nTerms;
        for(int i = 0; i<a.nTerms; i++){ term[i] = a.term[i]; }
        for(int i = a.nTerms; i<nTerms; i++){ term[i] = b.term[i-a.nTerms]; }
        for(int i= 0; i<nTerms; i++){ // 동차항 덧셈처리
            for(int j = i+1; j<nTerms; ){
                if(term[i].expo == term[j].expo){
                    term[i].coef += term[j].coef;
                    for(int k = j; k<nTerms; k++){
                        term[k] = term[k+1];
                    }
                    nTerms--;
                }
                else{ j++; }
            }
        }
        for(int i = 0; i<nTerms; i++){ //차수에 따른 배열 순서 정렬
            for(int j = i; j<nTerms; j++){
                if (term[i].expo < term[j].expo){
                    int tempExpo = 0;
                    float tempCoef = 0;
                    tempExpo = term[i].expo;
                    term[i].expo = term[j].expo;
                    term[j].expo = tempExpo;
                    tempCoef = term[i].coef;
                    term[i].coef = term[j].coef;
                    term[j].coef = tempCoef;
                }
            }
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