// Infix2Postfix.cpp
#include "ArrayStack.h"

//if A*B+C => AB*C+
//if (A+B)*C => AB+C*

inline int precedence ( char op ){
    switch( op ) {
        case '(' : case ')' : return 0;
        case '+' : case '-' : return 1;
        case '*' : case '/' : return 2;
    }
    return -1;
}

void infix2Postfix( FILE *fp = stdin ){
    char c, op;
    double val;
    ArrayStack st;

    while ( (c=getc(fp)) != '\n' ) {
        if((c>='0') && (c<='9')){
            ungetc( c, fp ); // c가 숫자일경우 fp에 반환
            fscanf( fp, "%lf", &val); // fp에 입력되어있는 숫자를(한자리 이상의 숫자 또한) 실수 형태로 val 형태로 저장
            printf("%4.1f", val);
        }

        else if ( c == '(') { st.push(c); }
        else if ( c == ')') {
            while (!st.isEmpty()) {
                op = st.pop();
                if( op == '(') break;
                else printf( "%c ", op);
            }
        }
        
        else if ( c == '+' || c == '-' || c == '/' || c == '*'){
            while (!st.isEmpty()){
            op = st.peek();
            if ( precedence(c) <= precedence(op) ) {
                printf( "%c ", op);
                st.pop();
            }
            else { break; }
        }
        st.push(c);
        }
    }
    while (!st.isEmpty()) { printf("%c ", st.pop() ); }
    printf( "\n");
}

int main() {
    printf("수식 입력 (Infix) = ");
    infix2Postfix();
}
