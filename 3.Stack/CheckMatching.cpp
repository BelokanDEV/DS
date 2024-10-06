#include "ArrayStack.h"
bool checkMatching( char* filename ){
    FILE *fp = fopen( filename, "r");
    if (fp == NULL){ error("ERROR : 존재하지 않는 파일입니다"); }
    int nLine = 1;
    int nChar = 0;
    ArrayStack stack;
    char ch, ch2;

    int bSingle, bDouble, bLineCmt, bMlineCmt;

    bSingle = bDouble = bLineCmt = bMlineCmt = 0;
    while((ch=getc(fp))!=EOF){
        ch2 = getc(fp);
        ungetc(ch2, fp);
        if(ch == '\n') { nLine++; }
        nChar++;

        if((bLineCmt == 1) && (ch == '\n')) { bLineCmt = 0; }
        if((bMlineCmt == 1) && ((ch == '*') && (ch2 == '/'))) { bMlineCmt = 0; }
        if(ch == 39 ) {bSingle = !bSingle; }
        if(ch == 34 ) {bDouble = !bDouble; }
        if((bLineCmt == 0) && ((ch == '/')&&(ch2 == '/'))) { bLineCmt = 1; }
        if((bMlineCmt == 0) && ((ch == '*')&&(ch2 == '/'))) { bMlineCmt = 1; }

        if(bSingle || bDouble || bLineCmt || bMlineCmt) {continue;}
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