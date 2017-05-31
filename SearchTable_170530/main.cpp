#include <iostream>

using namespace std;
struct staff{
    string name;
    int politics,chinese,math,english,total,level;
};

int main(){
    int n;
    cout<<"请输入招生人数: ";
    cin>>n;

    staff *employ = new staff[n+1];//为了使编号能对应数组下标

    int **q;//创建顺序数组//?????
    q = new int*[4];

    for(int i=0;i<4;i++)
        q[i]=new int[n+1];

    for(int i=0;i<4;i++) {//顺序数组初始化
        for (int j = 0; j < n + 1; j++)
            q[i][j]=0;
    }
    for(int i=0;i<4;i++){
        q[i][0]=i+1;
    }

    cout<<"依次输入每个人的姓名/政治成绩/语文成绩/数学成绩/英语成绩"<<endl;

    for(int i=1;i<=n;i++){
        cin>>employ[i].name>>employ[i].politics
           >>employ[i].chinese>>employ[i].math>>employ[i].english;

        employ[i].total = employ[i].politics+employ[i].chinese+
                                employ[i].math+employ[i].english;

        int sub1 = employ[i].politics>=60;//大于则输出1，否则输出0
        int sub2 = employ[i].chinese>=60;
        int sub3 = employ[i].math>=60;
        int sub4 = employ[i].english>=60;
        employ[i].level = 5-(sub1+sub2+sub3+sub4);
        //????????
        if(employ[i].level>3){//用于按照规定修改等级
            employ[i].level = 4;
        }
        for(int j=1;j<=n;j++){
            if(q[employ[i].level-1][j]==0){
                q[employ[i].level-1][j] = i;
                break;
            }
            else{
                if(employ[q[employ[i].level-1][j]].total>employ[i].total){}
                else{
                    for(int k=n;k>j;k--){
                        q[employ[i].level-1][k] = q[employ[i].level-1][k-1];
                    }
                    q[employ[i].level-1][j] = i;
                    break;
                }
            }
        }


    }
//    输出数据形成表格
    cout<<endl;
    for(int i=0;i<4;i++){
        cout<<q[i][0]<<"等级"<<endl;
        for(int j=1;j<n+1;j++){
            if(q[i][j]!=0){
                cout<<"**********ADMISSION NOTICE**********"<<endl;
                cout<<"               "<<employ[q[i][j]].name<<endl;
                cout<<"        You have been admitted"<<endl;
                cout<<"             Your score:"<<endl;
                cout<<"     Politics           "<<employ[q[i][j]].politics<<endl;
                cout<<"     Chinese            "<<employ[q[i][j]].chinese<<endl;
                cout<<"     Mathematics        "<<employ[q[i][j]].math<<endl;
                cout<<"     English            "<<employ[q[i][j]].english<<endl;
                cout<<"     Total              "<<employ[q[i][j]].total<<endl;
                cout<<"                       Yichao Ltd."<<endl;
            }
        }
    }
}
