#include <iostream.h>
#define MaxNum 100
typedef struct EdgeNode
{
	int ptpos;
	EdgeNode * next;
}*edgeptr;
typedef struct PointNode
{
	int data;
	EdgeNode * link;
}*ptptr;
typedef PointNode ptList[MaxNum];
int edgnum,ptnum;
ptList List;
int *visited =new int[ptnum+1];
void Create(ptList &pl)
{
	edgeptr p;
	edgeptr *tail = new edgeptr[ptnum+1];
	cin>>ptnum>>edgnum;
	for(int i=1;i<=ptnum;i++)
	{
		pl[i].data = i;
		pl[i].link = NULL;
		tail[i] = NULL;
	}
	for(int k=0;k<edgnum;k++)
	{
		int v1,v2;
		cout<<"input points:";
		cin>>v1>>v2;
		p = new EdgeNode;
		p->ptpos = v2;
		if(tail[v1] == NULL)
		{
			pl[v1].link = p;
			p->next = NULL;
			tail[v1] = p;
		}		
		else
		{
			tail[v1]->next = p;
			p->next = NULL;
			tail[v1] = p;
		}
		p = new EdgeNode;
		p->ptpos = v1;
		if(tail[v2] == NULL)
		{
			pl[v2].link = p;
			p->next = NULL;
			tail[v2] = p;
		}
		else
		{
			tail[v2]->next = p;
			p->next = NULL;
			tail[v2] = p;
		}
	}
	edgeptr test;
	for(i = 1;i<=ptnum;i++)
	{
		cout<<i<<" ";
		test = pl[i].link;
		while(test!=NULL)
		{
			cout<<test->ptpos<<" ";
			test = test->next;        
		}
		cout<<endl;
	}
			
}

void dfs(ptList pl,int V0)
{
	cout<<V0<<' ';
	visited[V0]=1;
	edgeptr p;
	p = pl[V0].link;
	while(p!=NULL)
	{
		if(visited[p->ptpos] == 0)
			dfs(pl,p->ptpos);
		p = p->next;
	}
}

void dfs2(ptList pl,int V0)
{
	int top=0;
	cout<<V0<<' ';
	visited[V0]=1;
	edgeptr p;
	edgeptr stack[MaxNum]={NULL};
	p = pl[V0].link;
	while(p!=NULL||top>0)
	{
		while(p!=NULL)
		{
			if(visited[p->ptpos] == 1)
				p = p->next;
			else
			{
				int w = p->ptpos;
				cout<<w<<' ';
				visited[w] = 1;
				top++;
				stack[top] = p;
				p = pl[w].link;
			}
		}
		if(top>0)
		{
			p = stack[top];
			top--;
			p = p->next;
		}
	}
}

void bfs(ptList pl,int V0)
{	
	for(int i=1;i<=ptnum;i++)
		visited[i]=0;
	int queue[MaxNum],f=0,r=0;
	visited[V0] = 1;
	cout<<V0<<' ';
	edgeptr p;
	p = pl[V0].link;
	do
	{
		int v;
		while(p!=NULL)
		{
			v = p->ptpos;
			if(visited[v]==0)
			{
				r++;
				queue[r]=v;
				cout<<v<<' ';
				visited[v]=1;
			}
			p = p->next;
		}
		if(f!=r)
		{
			f++;
			v = queue[f];
			p = pl[v].link;
		}
	}while(p!=NULL||f!=r);
}
