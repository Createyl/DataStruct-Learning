#include <iostream>
using namespace std;

struct flight {
    int flightCode = 10000;
    int flightTicket = 0;
};

typedef struct BSList {
    flight flightInfo[50];//50个航次,每个航次一个位置存放余票量，每个航班100张票
    int length;//此线性表实际的长度
} BSListA;

typedef struct _PassengerLink {
    string name;//乘客姓名
    int ticketPasg = 0;//乘客持有的票数
    int ticketNumFlight;
    struct _PassengerLink * LLink;//前驱链域
    struct _PassengerLink * RLink;//后继链域
} PassengerLink,* PassengerLinkPtr;

void initList(BSListA *&BS) {
    BS = new BSListA;
    BS->length = 0;
}

BSList *BS;

void createList(BSListA *&BS) {
    int i;
    int flightNum;
    cout << "请输入总共有几个航班" << endl;
    cin >> flightNum;
    BS->length = flightNum;
    cout << "所有航班:" << endl;
    for (i = 0; i < flightNum; i++) {
        BS->flightInfo[i].flightTicket = 100;//初始化，每个航班100张票
        BS->flightInfo[i].flightCode = 10000 + i;//初始化，每个航班100张票
        cout << BS->flightInfo[i].flightCode << endl;
    }
}

PassengerLinkPtr createDoubleLink(int num){

    PassengerLinkPtr head = NULL, curr = NULL, prev = NULL ;

    head = new PassengerLink;
    prev = head;

    for(int i=1 ; i < num ; i++){
        curr = new PassengerLink;
        prev->RLink = curr;
        curr->LLink = prev;
        prev = curr;
    }

    curr = new PassengerLink;
    prev->RLink = curr;
    curr->LLink = prev;
    curr->RLink = head;
    head->LLink = curr;
    return head;
}

void InsertLink(PassengerLinkPtr &head, string bookName, int ticketNumFlight, int ticketPasg) {//???head前面是*&还是&
    PassengerLinkPtr curr = NULL, node = NULL;
    curr = head->RLink;

    if(curr->name == ""){
        node = curr;
        node->name = bookName;
        node->ticketPasg = ticketPasg;
        node->ticketNumFlight = ticketNumFlight;
    }
    else{
        while((curr->name != "")&&(curr != head)){
            if(bookName == curr->name){
                if(ticketNumFlight == curr->ticketNumFlight){
                    curr->ticketPasg = curr->ticketPasg+ticketPasg;
                    curr->ticketNumFlight = ticketNumFlight;
                    node = curr;
                    break;
                }
                else{
                    node = new PassengerLink;
                    node->name = bookName;
                    node->ticketPasg = ticketPasg;
                    node->ticketNumFlight = ticketNumFlight;
                    node->RLink = curr->RLink;
                    node->RLink = curr;
                    (curr->RLink)->LLink = node;
                    curr->RLink = node;
                }
                break;
            }
            else{
                if(bookName > curr->name){
                    curr = curr->RLink;
                }
                else{
                    node = new PassengerLink;
                    node->name = bookName;
                    node->ticketPasg = ticketPasg;
                    node->ticketNumFlight = ticketNumFlight;
                    node->RLink = curr;
                    node->LLink = curr->LLink;
                    (curr->LLink)->RLink = node;
                    curr->LLink = node;
                    break;
                }
            }
        }
    }

    if(curr == head){
        node = new PassengerLink;
        node->name = bookName;
        node->ticketPasg = ticketPasg;
        node->ticketNumFlight = ticketNumFlight;
        node->RLink = head;
        node->LLink = curr;
        curr->RLink = node;
        head->LLink = node;
    }

    if(curr->name=="") {
        curr->name = bookName;
        curr->ticketPasg = ticketPasg;
        curr->ticketNumFlight = ticketNumFlight;
        node = curr;
    }

    cout << "\n您已成功订票航班号为: " <<node->ticketNumFlight<<"票数: "<< node->ticketPasg << " 张" << endl;
};

void DeleteLink(PassengerLinkPtr &head, string bookName, int ticketNumFlight) {
    PassengerLinkPtr curr = NULL;
    curr = head->RLink;
    while ((bookName != curr->name) && (curr != head))
        curr = curr->RLink;

    if (curr == head)
        cout << "此人无订票信息" << endl;
    if(bookName==curr->name){
        if(ticketNumFlight==curr->ticketNumFlight) {
            (curr->LLink)->RLink = curr->RLink;
            (curr->RLink)->LLink = curr->LLink;
            cout << "此人无订票数清除订票姓名信息";
        }
        else
            cout<<"定位到乘客但是未预订此次航班"<<endl;
    }
};

int GetLink(PassengerLinkPtr &head, string bookName) {
    PassengerLinkPtr prev = NULL;
    prev = head->RLink;
    while ((bookName != prev->name) && (bookName < prev->name) && (prev != head))
        prev = prev->RLink;
    return prev->ticketPasg;
}

void AlertLink(PassengerLinkPtr &head, string bookName, int ticketNumFlight,int ticketPasg) {

    PassengerLinkPtr curr = NULL;
    curr = head->RLink;

    while ((bookName != curr->name) && (curr != head))
        curr = curr->RLink;

    if(curr==head) {
        cout<<"未找到匹配项无法修改"<<endl;
    }
    if(curr!=head){
        if(bookName==curr->name){
            if(ticketNumFlight==curr->ticketNumFlight) {
                curr->ticketPasg = ticketPasg;
                cout<<"修改成功"<<endl;
            }
            else
                cout<<"定位到乘客但是未预订此次航班"<<endl;
        }
    }
}

void QueryLink(PassengerLinkPtr &head, string bookName) {//系统性学习函数，以及其返回类型
    PassengerLinkPtr prev = NULL;
    prev = head->RLink;
    while ((bookName != prev->name) && (bookName < prev->name) && (prev != head))
        prev = prev->RLink;
    cout << "姓名:" << prev->name << endl;
    cout << "预订的航班的班次:" << prev->ticketNumFlight << endl;
    cout << "预订的本次航班的票数:" << prev->ticketPasg << endl;
}

void book(BSListA *&BS,PassengerLinkPtr &head) {

    string bookName;
    int bookFlightCode;
    int bookNum = 0;

    cout << "请输入您要订票的航班" << endl;
    cin >> bookFlightCode;

    int i = 0;
    //此循环用于匹配乘客输入航班号与结构体中的航班号
    while (bookFlightCode != BS->flightInfo[i].flightCode) { i++; }
    cout << "当前航班的余票数量为:" << BS->flightInfo[i].flightTicket << endl;

    cout << "请输入您的姓名" << endl;
    cin >> bookName;

    cout << "请输入您要订票的数量" << endl;
    cin >> bookNum;


    if (bookNum < BS->flightInfo[i].flightTicket) {
        BS->flightInfo[i].flightTicket = BS->flightInfo[i].flightTicket - bookNum;
        InsertLink(head, bookName, bookFlightCode, bookNum);//出现问题
        cout << "余票还有: " << BS->flightInfo[i].flightTicket << " 张" << endl;
    }
    else {
        cout << "余票不足" << endl;
    }
}

void refund(BSList *&BS,PassengerLinkPtr &head) {//退票系统
    string refundName;
    int refundFlightCode;
    int refundNum = 0;

    cout << "请输入您要退票的航班" << endl;
    cin >> refundFlightCode;

    cout << "请输入您的姓名" << endl;
    cin >> refundName;

    cout << "您所持有的本航班的机票数量为" << endl;
    QueryLink(head, refundName);//!!!!!待测试

    cout << "请输入您的退票的数量" << endl;
    cin >> refundNum;
    int lastTicket = GetLink(head, refundName);

    if (refundNum > lastTicket)//!!!!!!!待测试
        cout << "错误信息:退票数量大于持有数量" << endl;
    else {//余票充足,进入订票系统
        int ticketPasg = lastTicket - refundNum;
        AlertLink(head, refundName, refundFlightCode,ticketPasg);
        if (ticketPasg == 0)
            DeleteLink(head, refundName, refundFlightCode);
    }
}

void initialize(BSList *&BS,PassengerLinkPtr &head){
    cout<<"\n请选择您要重置的航班编号"<<endl;
    int flightCode=0;
    cin>>flightCode;
    flightCode = flightCode -10000;
    BS->flightInfo[flightCode].flightTicket = 100;
    cout<<"航班信息重置成功"<<endl;
    flightCode = 10000;

    //遍历一遍双重链表 只要把航班号为flightCode的乘客信息删除

    PassengerLinkPtr curr = head->RLink;//!!!!

    while(curr!=head){
        if(flightCode==curr->ticketNumFlight) {
            //删除curr
            PassengerLinkPtr node = curr,temp = NULL;
            (node->RLink)->LLink = node->LLink;
            (node->LLink)->RLink = node->RLink;
            temp->RLink = node->RLink;
            node->LLink = NULL;
            node->RLink = NULL;
            curr = new PassengerLink;
            curr->RLink = temp->RLink;
        }
        curr = curr->RLink;
    }
    if(curr==head)
        cout<<"乘客表信息清除完成"<<endl;

};

int main() {
//    显示所有航次
    initList(BS);
    createList(BS);
    PassengerLinkPtr head = createDoubleLink(30);
    while(true) {
        cout << "请选择您要进行的操作 0:初始化系统 1:订票 2:退票 3:退出系统" << endl;
        int act;
        cin >> act;
        if (act == 0)initialize(BS,head);
        else if (act == 1)book(BS,head);
        else if (act == 2)refund(BS,head);
        else if (act == 3)return 0;
        else{ cout << "输入错误"; }
    }
}



