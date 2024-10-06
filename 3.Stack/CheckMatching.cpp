#include "ArrayStack.h"
bool checkMatching( char* filename ){
    FILE *fp = fopen( filename, "r");
    if (fp == NULL){ error("ERROR : 존재하지 않는 파일입니다"); }
    int nLine = 1;
    int nChar = 0;
    ArrayStack stack;
    char ch, ch2;

    int qCheck, dqCheck, lineCmt, mlineCmt;

    qCheck = dqCheck = lineCmt = mlineCmt = 0;
    while((ch=getc(fp))!=EOF){
        ch2 = getc(fp);
        ungetc(ch2, fp);
        if(ch == '\n') { nLine++; }
        nChar++;

        if((lineCmt == 1) && (ch == '\n')) { lineCmt = 0; }
        if((mlineCmt == 1) && ((ch == '*') && (ch2 == '/'))) { mlineCmt = 0; }
        if(ch == 39 ) {qCheck = !qCheck; }
        if(ch == 34 ) {dqCheck = !dqCheck; }
        if((lineCmt == 0) && ((ch == '/')&&(ch2 == '/'))) { lineCmt = 1; }
        if((mlineCmt == 0) && ((ch == '*')&&(ch2 == '/'))) { mlineCmt = 1; }

        if(qCheck || dqCheck || lineCmt || mlineCmt) {continue;}
        if( ch == '[' || ch == '(' || ch == '{') { stack.push(ch); }
            else if( ch == ']' || ch == ')' || ch == '}') {
                int prev = stack.pop();
                if( ( ch == ']' && prev != '[') 
                ||  ( ch == ')' && prev != '(') 
                ||  ( ch == '}' && prev != '{') ) { break; }
            }
    }
    fclose(fp);
    printf("[%s] 파일 검사결과 : \n", filename );
    if ( !stack.isEmpty() ) { printf("Error : 문제발견!(라인수 = %d, 문자수 %d)\n\n", nLine, nChar); }
    else { printf(" OK : 괄호닫기정상(라인수 = %d, 문자수 = %d)\n\n", nLine, nChar); }
    return stack.isEmpty();
}
int main(){
    checkMatching("ArrayStack.h");
    checkMatching("CheckMatching.cpp");
    printf(" 왼쪽 괼호 = ((((((\n");
    printf(" 오른쪽 괄호 = }}}}}}");
    return 0;
}