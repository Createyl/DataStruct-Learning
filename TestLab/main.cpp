#include <iostream>
#define maxsize 100
#define left 100
#define right 100
using namespace std;

typedef struct{//转置前的矩阵
    int i,j;//代表元素[i][j]
    int v;//代表此矩阵元素内存放的数据
}node;

typedef struct spmatrix{//三元组结构体
    int m,n,t;//代表经过三元组处理后的 行数 列数 非零元素个数
    node data[maxsize];//非零元素个数为maxsize-此结构体数组用于存储三元组-矩阵中每一个元素
};

void create(spmatrix *&a){
    cout<<"输入矩阵 行数 列数 非零元素个数"<<endl;
    cin>>a->m>>a->n>>a->t;
    cout<<"请输入非零元素所在的行号，列号，以及数据值"<<endl;
    for(int i=0;i<a->t;i++){
        cout<<"元素: "<<endl;
        cin>>a->data[i].i>>a->data[i].j>>a->data[i].v;
    }
}

void printmatrix(spmatrix *&a){
    int pti,ptj;
    int matrix[left][right];
    for(pti;pti<left;pti++){//完成对矩阵的初始化
        for(ptj=0;ptj->right;ptj++){
            matrix[pti][ptj]=0;
        }
    }
    for(int k=0;k<a->t;k++)//将每一个元素从三元组从提取出啦储存到常规矩阵中
        matrix[a->data[k].i][a->data[k].j]=a->data[k].v;

    //👇😆😁😄😂下面的算法用于打印常规矩阵🐱🐶
    for(int i=1;i<=(a->m);i++){
        cout<<"    "<<endl;
        for(int j=1;j<=(a->m);j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}

spmatrix * transpose(spmatrix *&a){//转置矩阵
    spmatrix * ts;
    ts = new spmatrix;
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

spmatrix * multiplication(spmatrix *&a,spmatrix *&b){

}

int main(){
    spmatrix *a,*b,*c;
    a = new spmatrix;
    b = new spmatrix;
    c = new spmatrix;
    cout<<"创建矩阵a"<<endl;
    create(a);
    cout<<"创建矩阵b"<<endl;
    create(b);
    //矩阵的乘法未实现
}