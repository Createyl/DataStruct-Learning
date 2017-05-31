#include<iostream>
#include"BT.h"
using namespace std;

int main()
{
	trnode root;
	Create(root);
	PreOrder(root);
	cout<<endl;
	InOrder(root);
	cout<<endl;
	PostOrder(root);
	cout<<endl;
    return 0;
}