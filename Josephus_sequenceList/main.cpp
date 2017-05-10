#include<iostream>
using namespace std;
#define Maxsize 30

struct JPlist {
    int data[Maxsize];
    int length;
};

typedef struct JPlist JPlistA;//此处JPlistA为JPlist的别名

void initList(JPlistA *&J){//引用变量

    J = new JPlistA;
    J->length=0;

}

void createList(JPlistA *&J){

    int i;
    int people;

    cout<<"请输入总人数"<<endl;
    cin>>people;
    J->length=people;

    for(i=0;i<people;i++){//把人数显示出来
        J->data[i] = i+1;
        cout<<J->data[i]<<" ";
    }
}

void displayList(JPlistA *&J){
    int m=0,n=0,i=0,j=0,x=0;//m:数到第m个人输出此人 n:从第几个人开始数

    cout<<"请输入间隔人数(数到第几个人？)"<<endl;
    cin>>m;
    cout<<"从第几个人开始数"<<endl;
    cin>>n;

    n=n-1;

    for(i=J->length;i>0;i--){
        x=(n+m-1)%i;
        cout<<J->data[x]<<" ";

        for(j=x;j<J->length;j++){
            J->data[j]=J->data[j+1];
        }


    }

}

int main(){
    JPlist *Jt;
    initList(Jt);//对函数引用传递
    createList(Jt);
    displayList(Jt);
    return 0;

}

//结构体的用法？-check
//数组的用法？-check
