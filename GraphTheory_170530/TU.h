#ifndef GRAPHTHEORY_170530_TU_H
#define GRAPHTHEORY_170530_TU_H

#include<iostream>
using namespace std;
#define MaxNum 100


typedef struct EdgeNode{//弧顶点的结构

    int adjvex;//该弧所指向的节点的位置 adjacency matrix多重邻接矩阵
    EdgeNode * next;//指向下一条弧的指针

} * PtrEdge;

typedef struct VertexNode{//顶点节点的结构
    int vertex;//顶点的信息
    PtrEdge link;//指向第一条依附该节点的弧
} * PtrVertex,VtList[MaxNum];

int edgeNum,VtNum;

VtList List;

int *visited = new int[VtNum+1];

void create(VtList &G){
    PtrEdge p;
    PtrEdge *tail = new PtrEdge[VtNum+1];
    cin>>VtNum>>edgeNum;
    for(int i=1;i<=)
}

void depthFirstSearchRecurs(VtList G,int V0){

}

void depthFirstSearchNormal(VtList G,int V0){

}

void breadthFirstSearch(VtList G,int V0){

}


#endif //GRAPHTHEORY_170530_TU_H
