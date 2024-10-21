#include <cstdio>
#include <cstdlib>
#define MAX_STACK_SIZE 100
inline void error(char* str){
    printf("%s",str);
    exit(1);
}
class ArrayStack{
    int data[MAX_STACK_SIZE];
    int top;
public :
    ArrayStack()
    :top(-1) {}
    bool isFull(){return top == MAX_STACK_SIZE -1;}
    bool isEmpty(){return top == -1;}
    void push(int e){
        if(isFull()){error("THE STACK IS FULL!");}
        top = top+1;
        data[top] = e;
    }
    int pop(){
        if(isEmpty()){error("THE STACK IS EMPTY!");}
        int temp = data[top];
        top = top -1;
        return temp;
    }
};
bool checkMatching(char* filename){
    FILE *fp = fopen(filename, "r");
    if(fp==NULL){printf("그런 파일 없음!");}
    int nLine = 1;
    int nChar = 0;
    char ch, ch2;
    char prevCh = '\0';
    ArrayStack stack;

    int bSingle, bDouble, bLineCmt, bMlineCmt;
    bSingle = bDouble = bLineCmt = bMlineCmt = 0;
    while((ch = getc(fp))!=EOF){
         ch2 = getc(fp);
        ungetc(ch2, fp);
        if(ch == '\n') { nLine++; }
        nChar++;

        if((bLineCmt==1)&&(ch=='\n')){bLineCmt = 0;}
        if((bMlineCmt==1)&&(ch=='*')&&(ch2=='/')){bMlineCmt = 0;}
        if((ch=='\'')&&(prevCh!='\\')){bSingle = !bSingle;}
        if((ch=='\"')&&(prevCh!='\\')){bDouble = !bDouble;}
        if((bLineCmt==0)&&(ch=='/')&&(ch2=='/')){bLineCmt = 1;}
        if((bMlineCmt==0)&&(ch=='/')&&(ch2=='*')){bMlineCmt = 1;}

        prevCh = ch;

        if(bLineCmt||bMlineCmt||bSingle||bDouble){ continue; }

        if(ch=='['||ch=='('||ch=='{'){
            stack.push(ch);
        }
        else if(ch==']'||ch==')'||ch=='}'){
            int temp = stack.pop();
            if((ch==']' && temp!='[')
            || (ch==')' && temp!='(')
            || (ch=='}' && temp!= '{')) {break;}
        }
    }
    fclose(fp); // 중요
    printf("[%s] 파일 검사결과 : \n", filename );
    if ( !stack.isEmpty() ) { printf("Error : 문제발견!(라인수 = %d, 문자수 %d)\n\n", nLine, nChar); }
    else { printf(" OK : 괄호닫기정상(라인수 = %d, 문자수 = %d)\n\n", nLine, nChar); }
    return stack.isEmpty();
}
int main(void){
    checkMatching("PR4_BANK.cpp");
    checkMatching("PR3_CheckMatching.cpp");
    return 0;
}