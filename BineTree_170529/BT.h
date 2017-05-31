#ifndef BINETREE_170529_BT_H
#define BINETREE_170529_BT_H

#include <iostream>
using namespace std;

typedef struct _treeNode{
    int data;
    _treeNode * Lchild, * Rchild;
}*PtrtreeNode,treenode;

//利用先序遍历建立一棵树
void createTree(PtrtreeNode &tr){
    int xdata;
    cout<<"请输入";
    cin>>xdata;

    tr = new treenode;
    tr->data = xdata;//先给根节点赋值

    if(xdata!=0){//0意味着此点为空节点
        createTree(tr->Lchild);
        createTree(tr->Rchild);
    }
}


//先序遍历
void DLR(PtrtreeNode root){
    cout<<root->data<<" ";

    if(root->Lchild->data!=0)
        DLR(root->Lchild);

    if(root->Rchild->data!=0)
        DLR(root->Rchild);
}//递归遍历

void preOrder(PtrtreeNode &tr){
    int top;
    PtrtreeNode x;
    PtrtreeNode stack[100]={NULL};

    if(tr == NULL) {
        cout << "空节点" << endl;
        return;
    }
    else{
        top = 0;//设置top为0即栈的第一个位置
        x = tr;
    }

    do{
        while(x->data != 0){
            cout<<x->data<<" ";
            if(x->Rchild->data!=0){
                top++;
                stack[top] = x->Rchild;//先把节点存在栈里
            }
            x = x->Lchild;
        }
        if(top!=0){
            x = stack[top];
            top--;
        }
    }while ((top!=0)||(x->data!=0));

}

//中序遍历
void LDR(PtrtreeNode root){
    if(root->Lchild->data!=0)
        LDR(root->Lchild);

    cout<<root->data<<" ";

    if(root->Rchild->data!=0)
        LDR(root->Rchild);
}//递归遍历

void inOrder(PtrtreeNode &tr){
    int top;
    PtrtreeNode x;
    PtrtreeNode stack[100]={NULL};

    if(tr == NULL) {
        return;
    }
    else{
        top = 0;
        x = tr;
    }

    do{
        if(x->data!=0){
            top++;
            stack[top] = x;
            x = x->Lchild;
        }
        else{
            x = stack[top];
            cout<<x->data<<" ";
            top--;
            x = x->Rchild;
        }
    }while (top!=0||(x->data!=0));
}


//后序遍历
void LRD(PtrtreeNode root){
    if(root->Lchild->data!=0)
        LRD(root->Lchild);

    if(root->Rchild->data!=0)
        LRD(root->Rchild);

    cout<<root->data<<" ";
}//递归遍历

void postOrder(PtrtreeNode &tr){
    int top;
    PtrtreeNode x,pre = NULL;
    PtrtreeNode stack[100]={NULL};

    if(tr == NULL) {
        cout << "空节点" << endl;
        return;
    }
    else{
        top = 0;
        x = tr;
        top++;
        stack[top] = x;//存放头结点
    }

    do{
        x = stack[top];
        if(((x->Lchild->data == 0)&&(x->Rchild->data==0))||
                (pre!=NULL&&(x->Lchild == pre|| x->Rchild == pre))){//说明孩子节点已经输出过，不必再进入

            cout<<x->data<<" ";
            top--;
            pre = x;
        }
        else{
            if(x->Rchild->data!=0){//先进后出
                top++;
                stack[top] = x->Rchild;
            }
            if(x->Lchild->data!=0){
                top++;
                stack[top] = x->Lchild;
            }
        }
    }while (top!=0);
}


#endif //BINETREE_170529_BT1_H

