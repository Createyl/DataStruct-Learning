#include<iostream>
#include"BT.h"
using namespace std;

int main(){
    PtrtreeNode root;
    createTree(root);
    cout<<"先序遍历"<<endl;
    preOrder(root);
    cout<<endl;
    cout<<"中序遍历"<<endl;
    inOrder(root);
    cout<<endl;
    cout<<"后序遍历"<<endl;
    postOrder(root);
    cout<<endl;
    return 0;
}