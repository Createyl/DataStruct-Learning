#include <iostream>
using namespace std;
#define max_vertex_num  9				//图的顶点数
			//弧节点的结构
typedef struct EdgeNode
{
	int adjvex; 						//该弧所指向的顶点位置
	EdgeNode *next; 				//指向下一条弧的指针
};
				//顶点节点结构
typedef struct Vnode
{
	int vertex;      						//顶点信息
    EdgeNode *link;				// 指向第一条依附该顶点的弧
}AdjList[max_vertex_num];
int visited[max_vertex_num] = {0};
void dfsd(AdjList g,int v){				//深度优先搜索 递归算法
	cout<<v<<" ";
	visited[v] = 1;
	EdgeNode *p;
	p=g[v].link;
	while(p!=NULL){
		if(visited[p->adjvex] == 0){
			dfsd(g,p->adjvex);
		}
		p = p->next;
	}
}
int f=0,r=0;
int Q[max_vertex_num];
void bfs(AdjList g,int v0){			//广度优先搜索
	cout<<v0<<" ";
	visited[v0] = 1;
	f=0,r=0;
	EdgeNode *p;
	p=g[v0].link;
	int v;
	do{
		while(p!=NULL){
			v=p->adjvex;
			if(visited[v] == 0){
				r++;
				Q[r]=v;
				cout<<v<<" ";
				visited[v] = 1;
			}
			p = p->next;
		}
		if(f!=r){
			f++;
			v=Q[f];
			p=g[v].link;
		}
	}while((p!=NULL)||(f!=r));
}

int main() {
	AdjList vnode;
	int i,n,k;
	EdgeNode *p,*pnext,*prenext;
	cout<<"请输入各个顶点 "<<endl;
	for(i=1;i<max_vertex_num;i++){
		cin>>vnode[i].vertex;
		vnode[i].link = NULL;
	}
	cout<<"请输入边的个数 "<<endl;
	cin>>n;
	cout<<"请输入边的信息 "<<endl;
	for(i=0;i<n;i++){
		cin>>k;
		p = new EdgeNode();
		pnext = vnode[k].link;
		prenext = pnext;

		while(pnext!=NULL){
			prenext = pnext;
			pnext=pnext->next;
		}

		if(prenext==NULL){

			vnode[k].link = p;
		}else{
			prenext->next = p;
		}

		cin>>p->adjvex;
	}

	cout<<"深度优先搜索："<<endl;
	dfsd(vnode,1);
	for(i=0;i<max_vertex_num;i++){
		visited[i]=0;
	} cout<<endl;
	cout<<"光度优先搜索："<<endl;
	bfs(vnode,1);
}