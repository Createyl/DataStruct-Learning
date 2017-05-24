#include <iostream>
using namespace std;

struct flight{
    int flightCode=10000;
    int flightTicket=0;
};

typedef struct BSList{
    flight flightInfo[50];//30个航次,每个航次一个位置存放余票量，每个航班100张票
    int length;//此线性表实际的长度
}BSListA;

typedef struct PassengerLink{
    string name;//乘客姓名
    int ticketPasg=0;//乘客持有的票数
    struct PassengerLink * LLink;//前驱链域
    struct PassengerLink * RLink;//后继链域
} * PassengerLinkPtr;

void initList(BSListA *&BS){
    BS = new BSListA;
    BS->length = 0;
}

void createList(BSListA *&BS){
    int i;
    int flightNum;
    cout<<"请输入总共有几个航班"<<endl;
    cin>>flightNum;
    BS->length=flightNum;
    for(i=0;i<flightNum;i++){
        BS->flightInfo[i].flightTicket = 100;//初始化，每个航班100张票
//        cout<< BS->flightInfo[i].flightTicket<<endl;
    }
}

PassengerLinkPtr createDoubleLink(int num){

    PassengerLinkPtr head = NULL, curr = NULL, prev = NULL ;

    int i;

    head = new PassengerLink;
    prev = head;

    for(i=1 ; i < num ; i++){
        curr = new PassengerLink;
//        成功创建双重链表并通过测试
//        curr->ticketPasg=i;
//        cout<<curr->ticketPasg;
//        cout<<&(curr->ticketPasg)<<endl;
        prev->RLink = curr;
        curr->LLink = prev;
        prev = curr;
    }
    curr = new PassengerLink;
//    curr->ticketPasg=100;
//    cout<<curr->ticketPasg;
//    cout<<&(curr->ticketPasg)<<endl;
    curr->RLink = head;
    head->LLink = curr;
    return head;
}

int main(){
//    BSList *BS;
//    initList(BS);
//    createList(BS);
    createDoubleLink(10);
    return 0;
}

//字符串大小比较测试代码:实验结论可以直接使用满足要求
string a,b;
cin>>a>>b;
if(a<b)cout<<"a<b";
else cout<<"a>b";
return 0;

