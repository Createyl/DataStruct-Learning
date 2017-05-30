#include<iostream.h>
#include"TU.h"
void main()
{
	cout<<"Input data for initializing(point,edge):";
	Create(List);
	for(int i=1;i<=ptnum;i++)
		visited[i] = 0;
	dfs2(List,1);
	cout<<endl;
	bfs(List,1);
	cout<<endl;

}
