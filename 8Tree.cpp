#include <cstdio>

class BinaryNode{
public :
    int data;
    BinaryNode* left;
    BinaryNode* right;
public :
    BinaryNode(int val = 0, BinaryNode* l = nullptr, BinaryNode* r = nullptr)
    : data(val), left(l), right(r) {}
    ~BinaryNode(){}

    void setData(int val){data = val;}
    void setLeft(BinaryNode* n){left = n;}
    void setRight(BinaryNode*n ){right = n;}
    int getData(){return data;}
    BinaryNode* getLeft(){return left;}
    BinaryNode* getRight(){return right;}
    bool isLeaf(){ return left == nullptr && right == nullptr; }
};

class BinaryTree{
    BinaryNode* root;
public :
    BinaryTree()
    : root(nullptr) {}
    bool isEmpty(){ return root == nullptr; }
    void setRoot(BinaryNode* n){root = n;}
    BinaryNode* getRoot() {return root;}
    int getCount(){ return isEmpty() ? 0 : getCount(root); }
    int getCount(BinaryNode *n){
        if(n == nullptr) return 0;
        else return 1 + getCount(n->getLeft()) + getCount(n->getRight());
    }
    int getLeafCount(){ return isEmpty() ? 0 : getLeafCount(root); }
    int getLeafCount(BinaryNode* n){
        if(n == nullptr) return 0;
        else if(n->isLeaf()) return 1;
        return getLeafCount(n->getLeft()) + getLeafCount(n->getRight());
    }
    int getHeight(){ return isEmpty() ? 0 : getHeight(root); }
    int getHeight(BinaryNode* n){
        if(n==nullptr) return 0;
        int hLeft = getHeight(n->getLeft());
        int hRight = getHeight(n->getRight());
        return (hLeft > hRight) ? hLeft+1 : hRight+1;
    }
    void preorder(){
        printf("\n preoder : ");
        preorder(root);
        printf("\n");
    }
    void preorder(BinaryNode* n){
        if( n != nullptr){
        printf(" [%c] ", n->getData());
        preorder(n->getLeft());
        preorder(n->getRight());
        }
    }

    int calcSize() {return calcSize(root); }
    int calcSize(BinaryNode* n){
        if(n == nullptr) return 0;
        return n->getData() + calcSize(n->getLeft()) + calcSize(n->getRight());
    }
//
    bool isEven(BinaryNode* n){
        if(n==nullptr || (n->getLeft() == nullptr && n->getRight() == nullptr )) return true;
        if(n->getLeft() == nullptr || n->getRight() == nullptr) return false;
        return isEven(n->getLeft()) && isEven(n->getRight());
    }
    bool isFull(){
        bool ret = isEven(root);
        printf("트리가 %s\n", ret ? "완전 이진 트리입니다" : "완전 이진 트리가 아닙니다");
        return ret;
    }
//

    int checklevel(BinaryNode* p, BinaryNode* n, int level){
        int ll = 0, lr = 0;
        if(p==n) { return level; }
        if(p->getLeft()!=nullptr) ll = checklevel(p->getLeft(), n, level+1);
        if(p->getRight()!=nullptr) lr = checklevel(p->getRight(), n, level+1);
        return (ll>0) ? ll : lr;
    }
    int level(BinaryNode* n){
        int level = 0;
        if(root != nullptr) { level = checklevel(root, n, 1); }
        printf("%s\n", (level > 0) ? " 노드의 레벨을 확인하였습니다 " : "트리에 해당 노드 존재 X");
        return level;
    }

    bool checkBalanced(BinaryNode* n){
        if(n == nullptr) return true;
        int lh = getHeight(n->getLeft());
        int rh = getHeight(n->getRight());
        int dh = rh - lh;
        if ( dh<-1 || dh>1 ) return false;
        if(!checkBalanced(n->getLeft())) return false;
        return checkBalanced(n->getRight());
    }
    bool isBalanced(){
        bool ret = checkBalanced(root);
        printf("트리가 %s\n", ret ? "균형잡힌 트리이다" : "균형잡혀있지않다");
        return ret;
    }

    int calcPathLength(BinaryNode* n, int level){
        if(n==nullptr) return 0;
        int llen = calcPathLength(n->getLeft(), level + 1);
        int rlen = calcPathLength(n->getRight(), level + 1);
        return llen + rlen + level;
    }
    int pathLength() {
        int len = calcPathLength(root, 0);
        printf("전체 경로 길이는 %d입니다.\n", len);
        return len;
    }

    void swapNodes(BinaryNode* n){
        if(n==nullptr) return;
        BinaryNode* tmp = n->getLeft();
        n->left = n->right;
        n->right = tmp;
        swapNodes(n->getLeft());
        swapNodes(n->getRight());
    }
    void reverse() {
        printf("\n 트리 좌우 반전");
        swapNodes(root);
    }

    int hasSameNode(BinaryNode* p, BinaryNode* n){
        if( n == nullptr || p == nullptr ) return 0;
        if( n == p ) return 1;
        return hasSameNode(p->left,n) + hasSameNode(p->right,n);
    }
    int isDisjointFrom(BinaryNode* p, BinaryNode* n){
        if(p == nullptr || n == nullptr) return 1;
        if(hasSameNode(p, n)) return 0;
        if(hasSameNode(p, n->left)) return 0;
        if(hasSameNode(p, n->right)) return 0;
        return 1;
    }

    bool checkValid(BinaryNode* n){
        if(n==nullptr) return 1;
        if(!isDisjointFrom(n->left,n->right)) return 0;
        if(!checkValid(n->left)) return 0;
        if(!checkValid(n->right)) return 0;
        return 1;
    }
    bool isValid() {
        int ret = checkValid(root);
        printf("트리가 %s\n", ret ? "유효합니다" : "유효하지 않습니다");
        return ret;
    }
};
int main()
{
	BinaryTree tree, tree2, tree3;
	BinaryNode *a, *b, *c, *d, *e, *f;

	//           A
	//       B       E
	//     C   D        F  
	c = new BinaryNode('C', NULL, NULL);
	d = new BinaryNode('D', NULL, NULL);
	f = new BinaryNode('F', NULL, NULL);
	b = new BinaryNode('B', c, d);
	e = new BinaryNode('E', NULL, f );
	a = new BinaryNode('A', b, e);

	tree.setRoot(a);

	printf(" ��� ���� = %d\n", tree.getCount( ));
	printf(" �ܸ� ���� = %d\n", tree.getLeafCount( ));
	printf(" Ʈ�� ���� = %d\n", tree.getHeight());

	tree.preorder();
	printf("(1)\n");
	tree.isFull();
	printf("(2)\n");
	tree.level(a);
	tree.level(b);
	tree.level(c);
	tree.level(d);
	tree.level(e);
	tree.level(f);

	printf("(3)\n");
	tree.isBalanced();

	printf("(4)\n");
	tree.pathLength();


	printf("(5)");
	tree.reverse();
	tree.preorder();

	printf("(6)\n");
	printf("��Ʈb�� Ʈ���� ��Ʈe�� Ʈ���� Disjoint %s.\n", 
		tree.isDisjointFrom(b, e) ? "�մϴ�" : "���� �ʽ��ϴ�");

	printf("(7)\n");
	tree.isValid();
}