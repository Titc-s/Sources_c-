#include<iostream>
#include<fstream>
#include<Windows.h>
#include<stdlib.h>
#include<string>
#include<malloc.h>

using namespace std;

typedef struct AddressBook ABook;
typedef struct AddressBook
{
    string Name;
    string Street;
    string City;
    string Eip;
    string State;
    string MoblieNumber;
    string QQ;

    ABook *next;
    ABook *prev;
}ABook;

ABook a0={"0","0","0","0","0","0","0",NULL,NULL};
ABook an={"0", "0", "0", "0","0", "0", "0", NULL, NULL};   //结点初始化；
ABook *head = &a0;// 设置头指针

void OutAddressWindow()
{
    cout<<"*******************************"<<endl;
    cout<<"*** *** *** *** *** *** *** ***"<<endl;
    cout<<"**      1.输入信息            **"<<endl;
    cout<<"**      2.显示信息            **"<<endl;
    cout<<"**      3.查找以姓名作为关键字**"<<endl;
    cout<<"**      4.删除信息            **"<<endl;
    cout<<"**      5.存档               **"<<endl;
    cout<<"**      0.退出                **"<<endl;
    cout<<"*** *** *** *** *** *** *** ***"<<endl;
    cout<<"*******************************"<<endl;
}

void enter(ABook *a)//输入信息
{
    string name, mobilenum, street, city, eip, state, qq;
    cout << "请输入姓名：";
    cin >> name;
    a->Name = name;
    cout << "请输入电话号码：";
    cin >> mobilenum;
    a->MoblieNumber = mobilenum;
    cout << "请输入街道信息：";
    cin >> street;
    a->Street = street;
    cout << "请输入所在城市：";
    cin >> city;
    a->City = city;
    cout << "请输入邮政编码：";
    cin>>eip;
    a->Eip = eip;
    cout << "请输入所在国家：";
    cin >> state;
    a->State = state;
    cout<<"请输入QQ号：";
    cin >> qq;
    a->QQ = qq; 
}

ABook* AddNode()  //插入新节点，输入新信息
{
    ABook *a = new ABook;
    enter(a);
    a->next = head->next;
    head->next = a;
    a->prev = head;
    a->next->prev = a;
    head = a;
    return a;
}

ABook* search(string name)
{
    ABook *a;
    a = &an;
    for (a; a->prev != NULL;a=a->prev){
        if(a->Name==name)
            return a;
    }
    return NULL;
}

int deleteNode(string name)
{
    ABook *a;
    a = &an;
    for (a; a->prev != NULL;a=a->prev)
    {
        if(a->Name==name)
        {
            head = an.prev;
            a->prev->next = a->next;
            a->next->prev = a->prev;
            free(a);
            return 0;
        }
    }
    cout << "此人信息未被收录/不在通讯录中！" << endl;
    return 0;
}

void save()
{
    ABook *a;
    a = &an;
    int i = 1;
    ofstream fout("Address.txt");  //输出到Address.txt中

    while(a->prev!=NULL)
    {
        fout << i << ":" << a->Name << endl;//把当前结点 的信息保存到Address.txt中
        fout << "  " << a->MoblieNumber << endl;
        fout << "  " << a->Street << endl;
        fout << "  " << a->City << endl;
        fout << "  " << a->State << endl;
        fout << endl;
        a = a->prev;
        i++;
    }
    fout.close();
}

void Display(ABook *a) //按名字展示信息
{
    if(a==NULL){
        cout << "此人不在通讯录中!" << endl;
    }
    else{ 
        cout<<"*** *** *** *** *** *** *** *** *** *** *** *** *** ***"<<endl;
        cout<<"**              姓名："<<a->Name<<"                         **"<<endl;
        cout<<"**              电话："<<a->MoblieNumber<<"                    **"<<endl;
        cout<<"**              QQ："<<a->QQ<<"                           **"<<endl;
        cout<<"**              邮编："<<a->Eip<<"                         **"<<endl;
        cout<<"**              街道："<<a->Street<<"                         **"<<endl;
        cout<<"**              城市："<<a->City<<"                           **"<<endl;
        cout<<"**              国家："<<a->State<<"                           **"<<endl;
        cout<<"*** *** *** *** *** *** *** *** *** *** *** *** *** ***"<<endl;

    }
}

void DisplayName()
{
    ABook *a;
    a = head;
    int i = 1;
    cout << endl;
    cout<<"*** *** *** *** *** *** *** *** *** *** *** ***"<<endl;
    cout<<"                       通讯录                   "<<endl;
    cout<<"==============================================="<<endl;
    while(a->prev!=NULL)
    {
        cout << " " << i << ":     " << a->Name << endl;
        cout << "----------------------------------------------" << endl;
        a = a->prev;
        i++;
    }
    cout << "*** *** *** *** *** *** *** *** *** *** *** ***" << endl;
    cout << endl;
    cout << "通讯录所有人已遍历完成！" << endl;
}

void End()
{
    cout << endl
         << endl
         << endl;
    cout << "===============================" << endl
         << "\t\t\t       感谢使用本系统" << endl
         << "\t\t\t---------------------" << endl
         << endl
         << "                  wish you have a nice day!Bye~      XD" << endl;
    Sleep(5000);
}

void  Addressbook()
{
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
     cout<<"\t\t          请输入要进行的操作代码以继续:"<<' ';
     int choose = 0;
     string name;
     a0.next = &an;
     an.prev = &a0;
    

    while(1)
    {
        cin >> choose;
        switch(choose){
            case 1:
                AddNode();
                cout << "信息录入成功！" << endl;
                OutAddressWindow();
                break;
            case 2:
                DisplayName();
                OutAddressWindow();
                break;
            case 3:
                cout << "请输入查找的姓名：";
                cin >> name;
                Display(search(name));
                OutAddressWindow();
                break;
            case 4:
                cout << "请输入要删除的姓名：";
                cin >> name;
                deleteNode(name);
                OutAddressWindow();
                break;
            case 5:
                save();
                break;
            case 0:
                End();
                exit(0);
                break;
            default:
                cout<<"请重新输入正确的操作序号！"<<endl;
                OutAddressWindow();
                break;
        }
    }
}

int main()
{
   cout<<"\t\t\t**************************************"<<endl;
     cout<<"\t\t\t**************************************"<<endl;
     cout<<"\t\t\t**                                  **"<<endl;
     cout<<"\t\t\t**          1.通讯录系统              **"<<endl;
     cout<<"\t\t\t**          2.查看距离结点              **"<<endl;
     cout<<"\t\t\t**          3.图书管理系统            **"<<endl;
    cout<<"\t\t\t**         4.排序？                     **"<<endl;
     cout<<"\t\t\t**          0.退出                  **"<<endl;
     cout<<"\t\t\t**                                  **"<<endl;
     cout<<"\t\t\t**************************************"<<endl;
     cout<<"\t\t\t**************************************"<<endl;
     cout<<"\t\t          请输入要进行的操作代码以继续:"<<' ';

     int choose = 0;
     while(1)
     {
         cin >> choose;
         switch(choose)
         {
             case 1:
                 Addressbook();
                 break;
            case 0:
                exit(0);
                return 0;
         }
     }

     return 0;
}