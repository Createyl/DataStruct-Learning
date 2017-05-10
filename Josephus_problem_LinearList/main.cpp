#include <iostream>
using namespace std;
#define Maxsize 30

struct JPList{
        int data[Maxsize];
        int length;
};

typedef struct JPList JPList1;

void InitList(JPList1 *&L){
//    L = (JPList1 *)malloc(sizeof(JPList1));
    L = new JPList1;//C++可以替代此方法
    L->length=0;
}

void CreateList(JPList1 *&L){
    int i;
    int people;
    cout<<"请输入总人数n:";
    cin>>people;//?
    L->length=people;
    for(i=0;i<people;i++){
        L->data[i]=i+1;
        cout<<L->data[i]<<" ";
    }

}

void DisplayList(JPList1 *&L){//算法核心
    int m=0,i=0,j=0,x=0;//m:报数出队的间隔 x:数到第几个人

    cout<<endl;
    cout<< "请输入报数出队的间隔（数到第几个人）m:";
    cin>>m;
    cout<<"请输入第一个报数人的位置x:";
    cin>>x;

    x=x-1;
    //输出第一个人报数出队的人的位置x，因为数组在程序中起始点为0

//    cout<<L->data[x];//把第一个人的位置输出
//    for(j=x;j<L->length;j++){//把第一次输出的第x个位置从顺序表中删除
//        L->data[j]=L->data[j+1];
//    }
//    L->length=L->length-1;


    for(i=L->length;i>0;i--){

        x=(x+m-1)%i;// 输出第?+1个人为此轮出队，整个算法的核心，-1是因为x在data数组中以0为起点
        cout<<L->data[x]<<" ";

        for(j=x;j<i-1;j++){//把此处输出的位置从顺序表中删除
            L->data[j]=L->data[j+1];
        }

        L->length=L->length-1;
    }
}


int main(){
    JPList *Lx;//check
    InitList(Lx);
    CreateList(Lx);
    DisplayList(Lx);
    return 0;
}
