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
    int ticketNumFlight;
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

void InsertLink(PassengerLinkPtr &head, string bookName, int ticketNumFlight, int ticketPasg) {//???head前面是*&还是&
//不用再PassengerLinkPtr后面加*？
    PassengerLinkPtr curr = NULL, node = NULL;
    curr = head->RLink;

    //未进入循环,成立才循环，说明不成立 curr->name 为空 无法比较 空串小于任何有内容的串
    if(curr->name!=""){//空字符
        while((bookName != (curr->name)) && (curr != head)){//还是没有进入循环
            if(bookName < curr->name){
                //在head和curr中间插一个
                node = new PassengerLink;
                node->name = bookName;
                node->ticketPasg = ticketPasg;
                node->ticketNumFlight = ticketNumFlight;
                node->RLink = curr;
                node->LLink = curr->LLink;
                (curr->LLink)->RLink = node;
                curr->LLink = node;
            }
            else{
                //在curr的下一个插入
                node = curr->RLink;
                node->name = bookName;
                node->ticketPasg = ticketPasg;
                node->ticketNumFlight = ticketNumFlight;

            }
            curr = curr->RLink;
            cout<<"姓名"<<curr->name<<endl;
        }

    }
    else{//curr->name==空字符
        node = curr;
        node->name = bookName;
        node->ticketPasg = ticketPasg;
        node->ticketNumFlight = ticketNumFlight;
    }

//    if(curr==head){
//        node = new PassengerLink;
//
//        node->name = bookName;
//        node->ticketPasg = node->ticketPasg + ticketPasg;
//        node->ticketNumFlight = ticketNumFlight;
//        node->RLink = curr->RLink;
//        node->LLink = curr;
//        (curr->RLink)->LLink = node;
//        curr->RLink = node;
//    }
//    if(curr != head) {
//
//        node = curr;
//
//        node->name = bookName;
//        node->ticketPasg = node->ticketPasg + ticketPasg;
//        node->ticketNumFlight = ticketNumFlight;
//        node->RLink = curr->RLink;
//        node->LLink = curr;
//        (curr->RLink)->LLink = node;
//        curr->RLink = node;
//    }
    cout << "\n 您已成功订票航班号为: " <<node->ticketNumFlight<<"票数: "<< node->ticketPasg << " 张" << endl;
    cout << "地址"<<&(node);
    cout << "地址"<<&(head);
    cout << "地址"<<&(curr);

};

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

