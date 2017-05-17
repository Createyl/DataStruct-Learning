//
// Created by 刘逸超 on 2017/5/17.
//

#include <iostream>
using namespace std;

typedef struct _LinkNode{
    int value;
    struct _LinkNode * next;
}LinkNode, * LinkNodePtr;

LinkNodePtr createCycle(int total){

    int index = 1;
    LinkNodePtr head = NULL, curr = NULL, prev=NULL;
    head = new LinkNode;
    head->value = index;
    prev = head;

    while(--total>0){
        curr = new LinkNode;
        curr->value = ++index;
        prev->next = curr;
        prev = curr;
    }
    curr->next = head;
    return head;
}

void run(int total , int tag , int begin){

    LinkNodePtr node = createCycle(total);
    LinkNodePtr prev = NULL;

    while(begin-1>0){
        prev = node;
        node = node->next;
        begin--;
    }

    int start = 1;
    int index = start;

    while(node && node->next) {
        if(index==tag){
            cout<<node->value<<endl;

            prev->next = node->next;
            node->next = NULL;
            node = prev->next;

            index = start;
        }
        else{
            prev = node;
            node = node->next;
            index++;
        }
    }
}

int main() {
    int a,b,c;
    cin>>a>>b>>c;
    run(a,b,c);
    return 0;
}
