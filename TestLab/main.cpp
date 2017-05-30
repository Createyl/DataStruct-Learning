#include <iostream>
#define maxsize 100
#define left 100
#define right 100
using namespace std;
#include "1.cpp"

typedef struct{//原始存储的矩阵的单个元素
    int i,j;//元素[i][j]
    int data;//代表此矩阵元素内存放的数据
}node;

typedef struct _tripleMatrix{//代表一整个矩阵的三元组存储形式
    int m,n,t;              //行数 列数 非零元素个数
    node Element[maxsize];  //非零元素个数为maxsize-此结构体数组用于存储三元组-矩阵中每一个元素
}tripleMatrix;

void create(tripleMatrix *&a){
    cout<<"输入矩阵 行数 列数 非零元素个数"<<endl;
    cin>>a->m>>a->n>>a->t;
    cout<<"请输入非零元素所在的行号，列号，以及数据值"<<endl;
    for(int i=1;i <= a->t;i++){
        cout<<"第 "<<i<<" 个元素: ";
        cin>>a->Element[i].i>>a->Element[i].j>>a->Element[i].data;
    }
}//√

void print(tripleMatrix *&a){

    int matrix[left][right];

    for(int i=0;i<left;i++){//完成对矩阵的初始化
        for(int j=0;j->rightj++){
            matrix[i][j]=0;
        }
    }

    for(int x=1;x<a->t;x++)//将每一个元素从三元组从提取出啦储存到常规矩阵中
        matrix[a->Element[x].i][a->Element[x].j]=a->Element[x].data;

    //下面的算法用于打印常规矩阵
    for(int i=1;i<=(a->m);i++){
        cout<<"    "<<endl;
        for(int j=1;j<=(a->n);j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}

tripleMatrix * transpose(tripleMatrix *&a){//转置矩阵
    tripleMatrix * ts;
    ts = new tripleMatrix;
    ts->m = a->n;
    ts->n = a->m;
    ts->t = a->t;

    if(a->t>0){//?
        int q = 0;
        for(int col=0; col <= (a->n); col++){//列
            for(int p=0;p<a->t;p++){
                if(a->data[p].j==col){
                    ts->data[q].i = a->data[q].j;
                    ts->data[q].j = a->data[q].i;
                    ts->data[q].v = a->data[q].v;
                    q++;
                }
            }
        }
    }
}

tripleMatrix * multiplication(tripleMatrix *&a,tripleMatrix *&b){

}



int main(){
    tripleMatrix *a,*b,*c;
    a = new tripleMatrix;
    b = new tripleMatrix;
    c = new tripleMatrix;
    cout<<"创建矩阵a"<<endl;
    create(a);
    print(a);
    cout<<"创建矩阵b"<<endl;
    create(b);
    print(b);



    //矩阵的乘法未实现
}