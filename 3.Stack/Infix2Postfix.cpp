// Infix2Postfix.cpp
#include "ArrayStack.h"

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
        if( c == '
    }
}


