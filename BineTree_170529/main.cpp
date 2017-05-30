#include <iostream>
using namespace std;

typedef struct btnode{
    int data;
    struct btnode *Lchild, *Rchild;
} * bitreptr;

void CreateBtr(bitreptr &t){
    int x=0;
    cin>>x;
    if (x==0){
        t=NULL;
    }
    else{
        bitreptr p = new btnode;
        p->data = x;
        t = p;
        CreateBtr(t->Lchild);
        CreateBtr(t->Rchild);
    }
}

#include <iostream>
using namespace std;
typedef struct btnode
{
    int data;
    struct btnode *Lchild,*Rchild;
}*bitreptr;

void chushihua (btnode* tree){
    cin>>tree->data;
    if(tree->data!=0){
        tree->Lchild = new btnode();
        tree->Rchild = new btnode();
        chushihua(tree->Lchild);
        chushihua(tree->Rchild);
    }
}
void xianxubianli(btnode* tree){
    if(tree->data!=0){
        cout<<tree->data;
        xianxubianli(tree->Lchild);
        xianxubianli(tree->Rchild);
    }
}
void zhongxubianli(btnode *tree){
    if(tree->data!=0){
        zhongxubianli(tree->Lchild);
        cout<<tree->data;
        zhongxubianli(tree->Rchild);
    }
}
void houxubianli(btnode *tree){
    if(tree->data!=0){
        houxubianli(tree->Lchild);
        houxubianli(tree->Rchild);
        cout<<tree->data;
    }
}
int main(){
    bitreptr tree =new btnode();
    chushihua(tree);
    xianxubianli(tree);
    cout<<endl;
    zhongxubianli(tree);
    cout<<endl;
    houxubianli(tree);

}


int main() {
    return 0;
}