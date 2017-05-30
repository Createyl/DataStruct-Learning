#include<iostream.h>
#include"BT.h"

void main()
{
	trnode root;
	Create(root);
	PreOrder(root);
	cout<<endl;
	InOrder(root);
	cout<<endl;
	PostOrder(root);
	cout<<endl;
}