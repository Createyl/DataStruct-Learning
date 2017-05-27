#include <iostream>

using namespace std;

struct flight {
    int flightCode = 10000;
    int flightTicket = 0;
};

typedef struct BSList {
    flight flightInfo[50];//30个航次,每个航次一个位置存放余票量，每个航班100张票
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
//        cout<< BS->flightInfo[i].flightTicket<<endl;
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
//不用再PassengerLinkPtr后面加*？
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
                    curr = curr->RLink;//!!!!!!
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

//void DeleteLink(PassengerLinkPtr &head, string bookName) {
//    PassengerLinkPtr prev = NULL, next = NULL;
//    prev = head->RLink;
//    while ((bookName != prev->name) && (bookName < prev->name) && (prev != head))
//        prev = prev->RLink;
//    if (prev == head)
//        cout << "此人无订票信息" << endl;
//    else {
//        (prev->LLink)->RLink = prev->RLink;
//        (prev->RLink)->LLink = prev->LLink;
//        cout << "此人无订票数清除订票姓名信息";
//    }
//
//};
//
//int GetLink(PassengerLinkPtr &head, string bookName) {
//    PassengerLinkPtr prev = NULL, next = NULL;
//    prev = head->RLink;
//    while ((bookName != prev->name) && (bookName < prev->name) && (prev != head))
//        prev = prev->RLink;
//    return prev->ticketPasg;
//}
//
//void AlertLink(PassengerLinkPtr &head, string bookName, int ticketPasg) {
//    PassengerLinkPtr prev = NULL, next = NULL;
//    prev = head->RLink;
//    while ((bookName != prev->name) && (bookName < prev->name) && (prev != head))
//        prev = prev->RLink;
//    prev->ticketPasg = ticketPasg;
//}
//
//void QueryLink(PassengerLinkPtr &head, string bookName) {//系统性学习函数，以及其返回类型
//    PassengerLinkPtr prev = NULL, next = NULL;
//    prev = head->RLink;
//    while ((bookName != prev->name) && (bookName < prev->name) && (prev != head))
//        prev = prev->RLink;
//    cout << "姓名:" << prev->name << endl;
//    cout << "预订的航班的班次:" << prev->ticketNumFlight << endl;
//    cout << "预订的本次航班的票数:" << prev->ticketPasg << endl;
//};

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

//void refund(BSList *&BS) {//退票系统
//    string refundName;
//    int refundFlightCode;
//    int refundNum = 0;
//
//    cout << "请输入您要退票的航班" << endl;
//    cin >> refundFlightCode;
//
//    int i = 0;
//    cout << "请输入您的姓名" << endl;
//    cin >> refundName;
//
//    cout << "您所持有的本航班的机票数量为" << endl;
//    QueryLink(head, refundName);
//
//    cout << "请输入您的退票的数量" << endl;
//    cin >> refundNum;
//
//    if (refundNum > GetLink(head, refundName))
//        cout << "错误信息:退票数量大于持有数量" << endl;
//    else {//余票充足,进入订票系统
//        int ticketPasg = GetLink(head, refundName) - refundNum;
//        AlertLink(head, refundName, ticketPasg);
//        if (ticketPasg == 0)
//            DeleteLink(head, refundName);
//    }
//
//    /* 若该航次当前退票数小于等于乘客原订票数，
//     * 则在相应的乘客表中找到该乘客项，
//     * 修改该航次及乘客表中有关数据。
//     * 当由于退票，使得该乘客的订票数为0时，要从乘客表中撤销该乘客项；
//     * 否则，给出相应的提示信息。
//     * */
//}
//
//void initialize(BSList *&BS){};



int main() {
//    显示所有航次
    initList(BS);
    createList(BS);

    PassengerLinkPtr head = createDoubleLink(30);
//    string bookName;
//    int bookFlightCode;
//    int bookNum;
//    cin >> bookName;
//    cin >> bookFlightCode;
//    cin >> bookNum;
//    InsertLink(head, bookName, bookFlightCode, bookNum);

    while(2>1){
    book(BS, head);
    }


//    cout<<"请选择您要进行的操作 0:初始化系统 1:订票 2:退票"<<endl;
//    int act;
//    cin>>act;
//    if(act==0)initialize(BS);
//    else if(act==1)book(BS,head);
//    else if(act==2)refund(BS);
//    else{cout<<"输入错误";}
    return 0;
}



