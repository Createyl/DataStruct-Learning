#include<iostream>
#include<string>
using namespace std;
struct yuangong{
	string name;
	int zhengzhi,yuwen,shuxue,yingyu,zongfen;
	int leibie;
};
int main(){
	int n,i,j,k;
	cout<<"输入招生人数："<<endl;
	cin>>n;
	yuangong y[n+1];
	int q[4][n+1];				//顺序数组；
	for(i=0;i<4;i++){				//顺序数组初始化
		for(j=0;j<n+1;j++){
			q[i][j]=0;
		}
	}
	for(i=0;i<4;i++){
		q[i][0] = i+1;
	}
	cout<<" 输入每个人的姓名：政治成绩：语文成绩：数学成绩：英语成绩。"<<endl;
									//输入数据 并且排序
	for(i=1;i<=n;i++){
		cin>>y[i].name>>y[i].zhengzhi>>y[i].yuwen>>y[i].shuxue>>y[i].yingyu;
		y[i].zongfen = y[i].zhengzhi + y[i].yuwen + y[i].shuxue + y[i].yingyu;
		int z = y[i].zhengzhi>=60;
		int yw = y[i].yuwen>=60;
		int s = y[i].shuxue>=60;
		int yy = y[i].yingyu>=60;
		y[i].leibie = 5-(z+yw+s+yy);
		if(y[i].leibie>3){
			y[i].leibie = 4;
		}
		for(j=1;j<=n;j++){
			if(q[y[i].leibie-1][j]==0){
				q[y[i].leibie-1][j] = i;
				break;
			}else{
				if(y[q[y[i].leibie-1][j]].zongfen>y[i].zongfen){
					// 继续
				}else{
					for(k=n;k>j;k--){
						q[y[i].leibie-1][k] = q[y[i].leibie-1][k-1];
					}
					q[y[i].leibie-1][j] = i;
					break;
				}
			}
		}
	}
	/**************************输出 遍历  顺序数组输出 *****************************/
	cout<<endl;
	for(i=0;i<4;i++){
		cout<<q[i][0]<<" 类别 "<<endl;
		for(j=1;j<n+1;j++){
			if(q[i][j]!=0){
				cout<<y[q[i][j]].name<<" "<<y[q[i][j]].zhengzhi<<" "<<y[q[i][j]].yuwen<<" "<<y[q[i][j]].shuxue<<" "<<y[q[i][j]].yingyu<<" "<<y[q[i][j]].zongfen<<endl;
			}
		}
	}
}
