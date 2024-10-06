#include "OperandStack.h"

double calcPostfixExpr( FILE *fp = stdin ) {
    char c;
    OperandStack st;

    while ((c=getc(fp)) != '\n') {
        if ( c == '+' || c == '-' || c == '*' || c =='/') {
            double val2 = st.pop();
            double val1 = st.pop();
            switch ( c ) {
                case '+' : st.push( val1 + val2 ); break;
                case '-' : st.push( val1 - val2 ); break;
                case '*' : st.push( val1 * val2 ); break;
                case '/' : st.push( val1 / val2 ); break;
            }
        }
        else if (c>='0' && c<='9'){
            ungetc( c, fp);
            double val;
            fscanf( fp, "%lf", &val);
            st.push( val );
        }
    }
    return (st.pop());
}
int main() {
    printf("수식 입력 (Postfix) = ");
    double res = calcPostfixExpr();
    printf("계산결과 => %f\n",res);
    return 0;
}