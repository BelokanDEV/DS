#include<cstdio>
#include<cstdlib>

struct Term{
    int expon;
    float coeff;
public :
    Term(float coef = 0, int expo = 0)
    : expon(expo), coeff(coef) {}
  	void print() {
		if (coeff != 0.0f) {
			if (coeff > 0) printf("+");
			printf("%6.2f", coeff);
			if (expon != 0)printf("x^%d ", expon);
		}
	}
};

struct Node{
    Term data;
    Node* link;
    Node(float coe = 0.0f, int exp = 0)
    : data(coe, exp), link(nullptr) {}

    ~Node(){}

    Node* getLink(){return link;}
    void setLink(Node* n){link = n;}
    void insertNext(Node* next){
        next->setLink(link);
        link = next;
    }
    Node* removeNext(){
        Node* removed = link;
        if(removed!=nullptr){
        link = removed->link;
        }
        return removed;
    }
    void display(){
        data.print();
    }
};
class LinkedList{
    Node org;
public :
    LinkedList(){}
    ~LinkedList(){}

    void clear(){while(isEmpty())delete remove(0);}
    Node* getHead(){return org.getLink();}
    bool isEmpty(){return getHead()==nullptr; }
    Node* getEntry(int pos){
       Node *n = &org;
       for(int i = -1; i<pos; i++, n=n->getLink())
        if(n==nullptr) { break; }
        return n;
    }
    void insert(int pos, Node* n){
        Node* prev = getEntry(pos-1);
        if(prev!=nullptr){
            prev->insertNext(n);
        }
    }
    Node* remove(int pos){
        Node* prev = getEntry(pos-1);
        return prev->removeNext();
    }
    int size(){
        int count = 0;
        for(Node* p = getHead(); p!=nullptr; p=p->getLink()) {count++;}
        return count;
    }
    void display(const char* str = "내용 : "){
        printf("%s",str);
        for(Node*p = getHead(); p!=nullptr; p=p->getLink()){
            p->display();
        }
        printf("\n");
    }
};
class SparsePoly : public LinkedList{
    int expo;
    float coef;
    Term t;
public :
    void read(){
        int nterms;
        printf("항의 개수 입력 : \n");
        scanf("%d",&nterms);
        for(int i = 0; i<nterms; i++){
            printf("계수와 차수 입력 (ex : 3 5 -> 3x5^2) : \n");
            scanf("%f %d",&coef, &expo);
            insert(size(), new Node(coef, expo));
        }
        display();
    }
    void add(SparsePoly* A, SparsePoly* B){
        Node *i = A->getHead(), *j = B->getHead();
        Term t;

        while(i!=nullptr||j!=nullptr){
            if(i == nullptr || (j != nullptr)&&(i->data.expon < j->data.expon)){
                insert(size(), new Node(j->data.coeff,j->data.expon));
                j = j->getLink();
            }
            else if(j == nullptr || (i != nullptr)&&(i->data.expon > j->data.expon)){
                insert(size(), new Node(i->data.coeff,i->data.expon));
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
