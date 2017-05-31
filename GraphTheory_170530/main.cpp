#include <iostream>
#include "TU.h"
using namespace std;

int main(){
    cout<<"Input data for creating (point,edge)";
    create(G);
    for(int i=1;i <= VtNum; i++)
        visited[i] = 0;

    depthFirstSearchRecurs(G,1);
    cout<<endl;

    depthFirstSearchNormal(G,1);
    cout<<endl;

    breadthFirstSearch(G,1);
    cout<<endl;
}