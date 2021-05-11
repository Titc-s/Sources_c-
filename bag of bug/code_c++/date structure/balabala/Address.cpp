#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string>
#include<Windows.h>
using namespace std;

struct AddressBook{
    string NAME;//姓名
    string STREET;//街道
    string CITY;//城市
    string EIP;//邮编
    string STATE;//国家
    string MoblieNumber;//电话号码

    struct AddressBook* next;
    struct AddressBook* prev;
};

AddressBook a0={"0","0","0","0","0","0",NULL,NULL};
AddressBook an={"0","0","0","0","0","0",NULL,NULL};//头结点初始化
AddressBook *head=&a0;//设置头指针，指向头节点

void Output()//主界面
{
    cout<<"*******************************"<<endl;
    cout<<"*** *** *** *** *** *** *** ***"<<endl;
    cout<<"**      1.输入信息            **"<<endl;
    cout<<"**      2.显示信息            **"<<endl;
    cout<<"**      3.查找以姓名作为关键字**"<<endl;
    cout<<"**      4.删除信息            **"<<endl;
    cout<<"**      5.导出文档            **"<<endl;
    cout<<"**      0.退出                **"<<endl;
    cout<<"*** *** *** *** *** *** *** ***"<<endl;
    cout<<"*******************************"<<endl;
}
void enter(AddressBook *a)//单个节点输入
{
    string name,mobilenum,street,city,eip,state;
    cout<<"请输入姓名：";
    cin>>name;
    a->NAME=name;

    cout<<"请输入电话号码：";
    cin>>mobilenum;
    a->MoblieNumber=mobilenum;

    cout<<"请输入所在街道名称：";
    cin>>street;
    a->STREET=street;

    cout<<"请输入所在城市：";
    cin>>city;
    a->CITY=city;

    cout<<"请输入所在城市邮编：";
    cin>>eip;
    a->EIP=eip;

    cout<<"请输入所在国家：";
    cin>>state;
    a->STATE=state;
}

AddressBook* AddNode()//新建节点插入，链表
{
    AddressBook *a=new AddressBook;
    enter(a);

    a->next=head->next;
    head->next=a;
    a->prev=head;
    a->next->prev=a;
    head=a;
    return a;
}


AddressBook* Search(string name)//单个节点查找
{
    AddressBook *a;
    a=&an;
    for(a;a->prev!=NULL;a=a->prev){
        if(a->NAME==name){
            return a;
        }
    }
return NULL;
}

int Delete(string name)//单个节点删除
{
    AddressBook *a;
    a=&an;
    for(a;a->prev!=NULL;a=a->prev)
    {
        if(a->NAME==name)
        {
            head=an.prev;
            a->prev->next=a->next;
            a->next->prev=a->prev;
            free(a);
            return 0;
        }
    }
    cout<<"此人不在通讯录中！"<<endl;
    return 0;
}

void File()//导出文档
{
    AddressBook *a;
    a=&an;
    int i=1;
    ofstream fout("Address.txt");

    while(a->prev!=NULL)
    {
        fout<<i<<":"<<a->NAME<<endl;//把当前节点的名字输出到address.txt文件
        fout<<"  "<<a->MoblieNumber<<endl;
        fout<<"  "<<a->STREET<<endl;
        fout<<"  "<<a->CITY<<endl;
        fout<<"  "<<a->STATE<<endl;
        fout<<endl;
        a=a->prev;
        i++;
    }
    fout.close();//关闭文件流
}

void OutputMenu(AddressBook *a)//输出详细信息
{
    if(a==NULL){
        cout<<"此人不在通讯录中！"<<endl;
    }
    else{
        cout<<"*** *** *** *** *** *** *** *** *** *** *** *** *** ***"<<endl;
        cout<<"**              姓名："<<a->NAME<<"                         **"<<endl;
        cout<<"**              电话："<<a->MoblieNumber<<"                    **"<<endl;
        cout<<"**              邮编："<<a->EIP<<"                         **"<<endl;
        cout<<"**              街道："<<a->STREET<<"                         **"<<endl;
        cout<<"**              城市："<<a->CITY<<"                           **"<<endl;
        cout<<"**              国家："<<a->STATE<<"                           **"<<endl;
        cout<<"*** *** *** *** *** *** *** *** *** *** *** *** *** ***"<<endl;

    }
}

void OutputName()//输出通讯录（所有人名字）
{
    AddressBook *a;
    a=head;
    int i=1;
    cout<<endl;
    cout<<"*** *** *** *** *** *** *** *** *** *** *** ***"<<endl;
    cout<<"                       通讯录                   "<<endl;
    cout<<"==============================================="<<endl;
    while(a->prev!=NULL)
    {
        cout<<" "<<i<<":     "<<a->NAME<<endl;
        cout<<"-----------------------------------------------"<<endl;
        a=a->prev;
        i++;
    }
    cout<<"*** *** *** *** *** *** *** *** *** *** *** ***"<<endl;
    cout<<endl;
}


void thanks()//退出界面
{      cout<<"                                    "<<endl;
       cout<<"                                   "<<endl;
       cout<<"                                   "<<endl;
       cout<<"\t\t\t  ==========================="<<endl;
	   cout<<"\t\t\t          感谢使用本系统"<<endl;
	   cout<<"\t\t\t  --------------------------"<< endl;
       cout<<"\t\t\t  ==========================="<<endl;
       cout<<"\t\t\t                                        "<<endl;
	   Sleep(2000);
}



int main()
{
    system("CLS");
    cout << "***********************************\n\n\n";
    cout<<"\t 欢迎使用通讯录系统  \t\t\n\n\n";
    cout << "***********************************\n\n\n";
    cout<<"按任意键进入系统~";
    getchar();
    system("cls");

    cout<<"\t\t\t**************************************"<<endl;
     cout<<"\t\t\t**************************************"<<endl;
     cout<<"\t\t\t**         通讯录                   **"<<endl;
     cout<<"\t\t\t**                                  **"<<endl;
     cout<<"\t\t\t**          1.输入信息              **"<<endl;
     cout<<"\t\t\t**          2.显示信息              **"<<endl;
     cout<<"\t\t\t**          3.查找以姓名作为关键字  **"<<endl;
	 cout<<"\t\t\t**          4.删除信息              **"<<endl;
     cout<<"\t\t\t**          0.退出                  **"<<endl;
     cout<<"\t\t\t**                                  **"<<endl;
     cout<<"\t\t\t**         按Enter继续              **"<<endl;
     cout<<"\t\t\t**************************************"<<endl;
     cout<<"\t\t\t**************************************"<<endl;
     cout<<"\t\t          请输入0-4之间的任意一数字:"<<' ';
     int choose=0;
     string name;

     a0.next=&an;
     an.prev=&a0;

     while(1)
     {
         cin>>choose;
         switch(choose){
         case 1:
                AddNode();//新建节点并插入链表
                cout<<endl<<"信息录入成功！"<<endl;
                Output();
                break;
        case 2:
                OutputName();
                Output();
                break;
        case 3:
                cout<<"请输入要查找的姓名：";
                cin>>name;
                OutputMenu(Search(name));//打印找到所有节点的信息
                Output();
                break;
        case 4:
                cout<<"请输入姓名：";
                cin>>name;
                Delete(name);//删除节点（删除一个人的信息）
                Output();
                break;
        case 5:
                File();//输出文档
                break;
        case 0:
                thanks();//结束界面
                exit(0);
                break;
        default:
                break;
         }
     }
     return 0;
}
