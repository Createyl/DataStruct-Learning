#include<iostream>
#include<string>
using namespace std;
struct staff
{
	string name;
	int politics,literature,math,english,sum,level;
}; 
void main(){
	int n,i,j,k;
	cout<<"����������"; 
	cin>>n;
	staff *s= new staff[n+1];
	int **q;				//˳�����飻 
	q = new int*[4];
	for(i=0;i<4;i++)
		q[i]=new int[n+1];
	for(i=0;i<4;i++){				//˳�������ʼ�� 
		for(j=0;j<n+1;j++){
			q[i][j]=0;
		}
	}			
	for(i=0;i<4;i++){
		q[i][0] = i+1;
	}
	cout<<" ��������ÿ���˵�����,���γɼ�,���ĳɼ�,��ѧ�ɼ�,Ӣ��ɼ�,"<<endl; 
									//�������� �������� 
	for(i=1;i<=n;i++){
		cin>>s[i].name>>s[i].politics>>s[i].literature>>s[i].math>>s[i].english;
		s[i].sum = s[i].politics + s[i].literature + s[i].math + s[i].english;
		int pl = s[i].politics>=60;
		int lt = s[i].literature>=60;
		int mt = s[i].math>=60;
		int el = s[i].english>=60;
		s[i].level = 5-(pl+lt+mt+el);
		if(s[i].level>3){
			s[i].level = 4;
		}
		for(j=1;j<=n;j++){
			if(q[s[i].level-1][j]==0){
				q[s[i].level-1][j] = i;
				break;
			}else{
				if(s[q[s[i].level-1][j]].sum>s[i].sum){
					// ���� 
				}else{
					for(k=n;k>j;k--){
						q[s[i].level-1][k] = q[s[i].level-1][k-1];
					}
					q[s[i].level-1][j] = i;
					break;
				} 
			}
		}
	}
	/**************************��� ����  ˳��������� *****************************/
	cout<<endl;
	for(i=0;i<4;i++){
		cout<<q[i][0]<<" ��� "<<endl;
		for(j=1;j<n+1;j++){
			if(q[i][j]!=0){
				cout<<"			ADMISSION NOTICE"<<endl;
				cout<<"				"<<s[q[i][j]].name<<endl;
				cout<<"			You have been admitted"<<endl;
				cout<<"		  	Your Scores:"<<endl;
				cout<<"		Politics		"<<s[q[i][j]].politics<<endl;
				cout<<"		Chinese			"<<s[q[i][j]].literature<<endl;
				cout<<"		Mathematics		"<<s[q[i][j]].math<<endl;
				cout<<"		English			"<<s[q[i][j]].english<<endl;
				cout<<"		Total			"<<s[q[i][j]].sum<<endl;
				cout<<"					New Techonology Company"<<endl;
			}
		}
	} 
}