//约瑟夫环问题的原来描述为，设有编号为1，2，……，n的n(n>0)个人围成一个圈，从第1个人开始报数，报到m时停止报数，
// 报m的人出圈，再从他的下一个人起重新报数，报到m时停止报数，报m的出圈，……，如此下去，直到所有人全部出圈为止。
// 当任意给定n和m后，设计算法求n个人出圈的次序。  稍微简化一下。
//问题描述：n个人（编号0~(n-1))，从0开始报数，报到(m-1)的退出，剩下的人继续从0开始报数。求胜利者的编号。
#include <iostream>
using namespace std;

//chain list
typedef struct _LinkNode {
    int value;
    struct _LinkNode * next;
} LinkNode, * LinkNodePtr;

//结构体数据类型的函数，此函数的变量是结构体型
LinkNodePtr createCycle(int total) {
    int index = 1;
    LinkNodePtr head = NULL, curr = NULL, prev = NULL;
    head = (LinkNodePtr) malloc(sizeof(LinkNode));//动态分配空间
    head->value = index;//->是表示引用head结构体中的value元素，整体是一个变量，将index=1赋值给head结构体中的value变量
    prev = head;


    while (--total > 0) {
        curr = (LinkNodePtr) malloc(sizeof(LinkNode));
        curr->value = ++index;
        prev->next = curr;//将prev中的地址和curr串在一起
        prev = curr;
    }

    curr->next = head;//循环链表将头尾串在一起
    return head;
}


void run(int total, int tag) {//(总共有total个人，最开始杀掉第tag个人，然后杀掉第tag-1个人，以此类推)

    LinkNodePtr node = createCycle(total);//此时结构体链表节点位置在head
    LinkNodePtr prev = NULL;

    int start = 1;
    int index = start;


    while (node && node->next) {

        if (index == tag) {
            printf("\n%d", node->value);//输出第一个被杀的

            if (tag == start) {
                prev = node->next;
                node->next = NULL;
                node = prev;
            }
            else {
                prev->next = node->next;
                node->next = NULL;
                node = prev->next;
            }

            index = start;

        }
        else {
            prev = node;
            node = node->next;
            index++;
        }
    }
}


int main() {
    run(8, 3);//(5个人，杀人序列)
    return 0;
}