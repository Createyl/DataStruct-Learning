#ifndef BTTREE_TEST_BT_H
#define BTTREE_TEST_BT_H


#include<iostream>
using namespace std;

typedef struct BitreeNode
{
    int data;
    BitreeNode * lchild,* rchild;
}*trnode,treenode;

void Create(trnode &t)
{
    int d;
    cout<<"Input the data:";
    cin>>d;
    t = new treenode;
    t->data = d;
    if(d!=0)
    {
        Create(t->lchild);
        Create(t->rchild);
    }
}

void DLR(trnode root)
{
    cout<<root->data<<' ';
    if(root->lchild->data!=0)
        DLR(root->lchild);
    if(root->rchild->data!=0)
        DLR(root->rchild);
}

void PreOrder(trnode t)
{
    int top;
    trnode p;
    trnode stack[100]={NULL};
    if(t == NULL)
        return;
    else
    {
        top = 0;
        p = t;
    }
    do
    {
        while(p->data!=0)
        {
            cout<<p->data<<' ';
            if(p->rchild->data!=0)
            {
                top++;
                stack[top] = p->rchild;
            }
            p = p->lchild;
        }
        if(top!=0)
        {
            p = stack[top];
            top--;
        }
    }while((top!=0)||(p->data!=0));
}

void LDR(trnode root)
{
    if(root->lchild->data!=0)
        LDR(root->lchild);
    cout<<root->data<<' ';
    if(root->rchild->data!=0)
        LDR(root->rchild);
}

void InOrder(trnode t)
{
    int top;
    trnode p;
    trnode stack[100]={NULL};
    if(t==NULL)
        return;
    else
    {
        top=0;
        p = t;
    }
    do
    {
        if(p->data!=0)
        {
            top++;
            stack[top]=p;
            p = p->lchild;
        }
        else
        {
            p = stack[top];
            cout<<p->data<<' ';
            top--;
            p = p->rchild;
        }
    }while(top!=0||p->data!=0);
}

void LRD(trnode root)
{
    if(root->lchild->data!=0)
        LRD(root->lchild);
    if(root->rchild->data!=0)
        LRD(root->rchild);
    cout<<root->data<<' ';
}

void PostOrder(trnode t)
{
    int top;
    trnode p,pre=NULL;
    trnode stack[100]={NULL};
    if(t == NULL)
        return;
    else
    {
        top=0;
        p = t;
        top++;
        stack[top] = p;
    }
    do
    {
        p = stack[top];
        if((p->lchild->data==0&&p->rchild->data==0)||
                (pre!=NULL&&(p->lchild==pre||p->rchild==pre)))
        {
            cout<<p->data<<' ';
            top--;
            pre = p;
        }
        else
        {
            if(p->rchild->data!=0)
            {
                top++;
                stack[top] = p->rchild;
            }
            if(p->lchild->data!=0)
            {
                top++;
                stack[top] = p->lchild;
            }
        }
    }while(top!=0);
}


#endif //BTTREE_TEST_BT_H
