//约瑟夫环问题的原来描述为，设有编号为1，2，……，n的n(n>0)个人围成一个圈，从第1个人开始报数，报到m时停止报数，
// 报m的人出圈，再从他的下一个人起重新报数，报到m时停止报数，报m的出圈，……，如此下去，直到所有人全部出圈为止。
// 当任意给定n和m后，设计算法求n个人出圈的次序。  稍微简化一下。
//问题描述：n个人（编号0~(n-1))，从0开始报数，报到(m-1)的退出，剩下的人继续从0开始报数。求胜利者的编号。
#include <iostream>
using namespace std;

typedef struct _LinkNode {
    int value;
    struct _LinkNode * next;//因为结构体尚未定义完全所以此处还是要加struct
} LinkNode, * LinkNodePtr;//结构体型的类型，指针则为开辟了一个此结构体大小的空间


//结构体数据类型的函数，此函数的变量是结构体型
LinkNodePtr createCycle(int total) {//total作为参数传入

    int index = 1;
    LinkNodePtr head = NULL, curr = NULL, prev = NULL;  //创建三个结构体指针变量并赋值为空，本质地址
                                                        //当地址赋值为NULL时候，输出指针变量显示0x0，当指针有实际指向时输出才显示具体地址
    head = new LinkNode;
//    head = (LinkNodePtr) malloc(sizeof(LinkNode));//动态分配空间
    head->value = index;//->是表示引用head结构体中的value元素，整体是一个变量，将index=1赋值给head结构体中的value变量
    prev = head;//地址的赋值


    while (--total > 0) {//"--"在此步骤判断total减去1是否大于0//因为之前的头指针index为1已经占去一个位置
        curr = new LinkNode;
        curr->value = ++index;
        prev->next = curr;//将prev中的地址和curr串在一起，必要的
        prev = curr;//本质是地址的赋值 原本的内容还在内存中
    }

    curr->next = head;//循环链表将头尾串在一起
    return head;
}


void run(int total, int tag , int begin) {//(总共有total个人，tag为杀人间隔，以此类推)

    LinkNodePtr node = createCycle(total);//此时结构体链表节点位置在head
    LinkNodePtr prev = NULL;

    while(begin-1>0){
        prev = node;
        node = node->next;
        begin--;
    }

    int start = 1;//用于置1,不是序列开始标志，只是序列回到原位的标记
    int index = start;


    while (node && node->next) {//在条件表达式中只要不为NULL值则为1，为NULL值则为0
        //程序的核心，主要算法
//        while(--total>0){此处--total失效的原因在于内部是选择结构实际上tag个循环后才能减去一位而这时total已经减去了tag次，解决办法:在if子句的末尾加入total--
        if (index == tag) {

            cout<<node->value<<endl;

                prev->next = node->next;
                node->next = NULL;
                node = prev->next;//实质是node节点的移动一个位置(相当于删除原位置)

            index = start;

        }

//      算法解释:当index小于tag时，node指针不断移动直到移动到tag所指向的位置，并在后面把tag所指向位置的序号输出(所杀得第一个人)
        else {
            prev = node;
            node = node->next;
            index++;
        }
    }
}


int main() {
    run(8, 4, 1);// (total,tag,num)
                //(几个人，杀人间隔(数到第几个人),从第几个人开始数)
    return 0;
}

