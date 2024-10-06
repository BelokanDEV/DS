// Infix2Postfix.cpp
#include "ArrayStack.h"
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
    double var;
    ArrayStack st;

    while((c=getc(fp)) != '\n' ){
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){
            op = c;
            for(int i = 0; i<= st.data[top]; i++){
                if( precedence(op) < precedence(st.data[i]) )
            }
        }
    }
}


