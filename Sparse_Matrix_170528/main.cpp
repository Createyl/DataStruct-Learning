#include <iostream>
#define maxsize 100
#define left 100
#define right 100
using namespace std;

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
}//完成

void print(tripleMatrix *&a){

    int matrix[left][right];

    for(int i=0;i<left;i++){//完成对矩阵的初始化
        for(int j=0;j<right;j++){
            matrix[i][j]=0;
        }
    }

    for(int x=1;x<=a->t;x++)//将每一个元素从三元组从提取出啦储存到常规矩阵中
        matrix[a->Element[x].i][a->Element[x].j]=a->Element[x].data;

    //下面的算法用于打印常规矩阵
    for(int i=1;i<=(a->m);i++){
        cout<<"    "<<endl;
        for(int j=1;j<=(a->n);j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}//完成


tripleMatrix * transpose(tripleMatrix *&a){//转置矩阵 col a的列 ts的行
    tripleMatrix * ts;
    ts = new tripleMatrix;
    ts->m = a->n;
    ts->n = a->m;
    ts->t = a->t;

    if(a->t>0){
        int tsnum = 1;
        for(int col = 1; col <= (a->n); col++){
            for(int anum = 1 ; anum <= (a->t) ; anum++){
                if(a->Element[anum].j==col){
                    ts->Element[tsnum].i = a->Element[tsnum].j;
                    ts->Element[tsnum].j = a->Element[tsnum].i;
                    ts->Element[tsnum].data = a->Element[tsnum].data;
                    tsnum++;//加多一行
                }
            }
        }
    }
    return ts;
}//完成

void * multiplication(tripleMatrix *&a,tripleMatrix *&b){

    int matrix[a->m][b->n];
    int num[a->n],pot[a->n];

    if(a->n == b->m){
        if((a->t)*(b->t)!=0){

            for(int i=1; i<=(a->m); i++) {
                for (int j = 1; j <= (b->n); j++) {
                    matrix[i][j] = 0;
                }
            }

            for(int i=1; i<=(a->n); i++) {//初始化num数组
                num[i] = 0;
            }

            for(int i=1; i<=(b->t); i++) {
                num[b->Element[i].i] = num[b->Element[i].i] + 1;
            }

            pot[1]=1;
            for(int i=2; i<=(a->n)+1;i++) {
                pot[i] = pot[i - 1] + num[i - 1];
            }

            for(int i=1; i<=(a->t); i++){
                int k=a->Element[i].j;
                for(int j=pot[k];j<=pot[k+1]-1;j++) {
                    matrix[a->Element[i].i][b->Element[j].j] =
                            matrix[a->Element[i].i][b->Element[j].j] +
                            a->Element[i].data * b->Element[j].data;
                }
            }

            for(int i=1;i<=(a->m);i++){
                cout<<"    "<<endl;
                for(int j=1;j<=(b->n);j++)
                    cout<<matrix[i][j]<<" ";
                cout<<endl;
            }
        }

        else{
            cout<<"矩阵为零矩阵"<<endl;
        }
    }

    else{
        cout<<"矩阵不相容，无法相乘"<<endl;
    }
}



int main(){
    tripleMatrix *a,*b,*c;
    a = new tripleMatrix;
    b = new tripleMatrix;
    c = new tripleMatrix;

    cout<<"创建矩阵a"<<endl;
    create(a);
    print(a);

    cout<<"a的转置矩阵是:"<<endl;
    c = transpose(a);
    print(c);

    cout<<"创建矩阵b"<<endl;
    create(b);
    print(b);

    cout<<"b的转置矩阵是:"<<endl;
    c = transpose(b);
    print(c);

    cout<<"矩阵a*b的结果是:"<<endl;
    multiplication(a,b);

    return 0;
    //矩阵的乘法未实现
}