#include <cstdio>
#include <cstdlib>

struct term{
    float coeff;
    int expon;
    term(int coe = 0, int exp = 0)
    : coeff(coe), expon(exp){}
    void print(){
        if(coeff!=0){
            if(coeff>0){printf("+");}
            printf("%6.2f", coeff);
            if(expon!=0){printf("x^%d",expon);}
        }
    }
};
struct Node{
    term data;
    Node* link;
public :
    Node(float coe = 0.0f , int exp = 0)
    : data(coe, exp) {}
    Node* getLink(){return link;}
    void setLink(Node*n){link = n;}
    void insertNext(Node* n){
        n->setLink(link);
        link = n;
    }
    void display(){ data.print(); }
};
class LinkedList{
    Node org;
public :
    Node* getHead(){return org.getLink();}
    bool isEmpty(){return getHead() == nullptr; }
    Node* getEntry(int pos){
        Node *n = &org;
        for(int i = -1; i<pos; i++,n=n->getLink()){
            if(n==nullptr) {break;}
        }
        return n;
    }
    void insert(int pos, Node* n){
        Node* prev = getEntry(pos-1);
        if(prev!=nullptr){
            prev->insertNext(n);
        }
    }
    int size(){
        int count = 0;
        for(Node* p = getHead(); p!=nullptr; p=p->getLink() ){ count++; }
        return count;
    }
    void display(const char* str = "다항식 내용 : "){
        printf("%s",str);
        for(Node *p = getHead(); p!=nullptr; p=p->getLink()){
            p->display();
        }
        printf("\n");
    }
};
class SparsePoly : public LinkedList{
    float coef;
    int expo;
    term t;
    int nterms;
public :
    SparsePoly()
    : coef(0), expo(0), t(coef,expo) {}
    void read(){
        printf("다항식의 개수 입력 : \n");
        scanf("%d",&nterms);
        for(int i = 0; i<nterms; i++){
            printf("계수 차수 입력 (ex : 5 2 -> 5x^2) : ");
            scanf("%f %d", &coef, &expo);
            insert(size(),new Node(coef, expo));
        }
        display();
    }
    void add(SparsePoly* a, SparsePoly* b){
        Node* i = a->getHead();
        Node* j = b->getHead();
        while(i!=nullptr||j!=nullptr){
            if((i==nullptr)||(j!=nullptr)&&(i->data.expon < j->data.expon)){
                insert(size(), new Node(j->data.coeff, j->data.expon));
                j = j->getLink();
            }
            if((j==nullptr)||(i!=nullptr)&&(i->data.expon > j->data.expon)){
                insert(size(), new Node(i->data.coeff, i->data.expon));
                i = i->getLink();
            }
            else{
                t = i->data;
                t.coeff += j->data.coeff;
                insert(size(), new Node(t.coeff, t.expon));
                i = i->getLink();
                j = j->getLink();
            }
        }
    }

};
int main(void) {
    SparsePoly* a = new SparsePoly();  // a에 메모리 할당
    SparsePoly* b = new SparsePoly();  // b에 메모리 할당
    SparsePoly* c = new SparsePoly();  // c에 메모리 할당

    a->read();
    b->read();

    c->add(a, b);
    c->display("Poly C = ");

    // 메모리 해제
    delete a;
    delete b;
    delete c;

    return 0;
}