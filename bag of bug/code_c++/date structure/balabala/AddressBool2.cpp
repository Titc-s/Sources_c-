#include<iostream>
#include<fstream>
#include <stdlib.h>
#include<string>
using namespace std;


typedef struct Directory
{
    string Name;
    string Mobile;
    string Wechatnumber;
    string STREET;
    string CITY;
    string EIP;
    string STATE;

    struct Directory* next;
    struct Directory* prev;
}Directory;

//头节点初始化
Directory p0 = {"0","0","0","0","0","0","0",NULL,NULL};
Directory pn = {"0","0","0","0","0","0","0",NULL,NULL};

//设置头指针，指向头节点
Directory *head = &p0;

//函数声明
void enter(Directory*);
void display_list();
void printf_a();
void display_menu(Directory*);
int key_ramove(string);
void display_listfiile();
Directory* find_load(string);
Directory* load();

int main()
{
    cout<<"========================================"<<endl;
    cout<<"=              通 讯 录                ="<<endl;
    cout<<"=                                      ="<<endl;
    cout<<"=                                      ="<<endl;
    cout<<"= 1.添加  2.删除  3.查找  4.查看通讯录 ="<<endl;
    cout<<"========================================"<<endl;

    int i = 0;                              //定义按键变量，存放键值
    string key;                             //定义字符串变量，存放输入的字符串

    p0.next = &pn;                          //这俩句是初始化头尾节点，头尾节点连起来
    pn.prev = &p0;

    while(1)
    {
        cin>>i;                             //输入i，用于选择第几个功能
        switch(i){                          //选择，i等于几，就执行case几
        case 1:
            load();                         //新建节点并插入链表
            cout<<endl;
            cout<<"添加完成！！！"<<endl;
            printf_a();
            break;
        case 2:
            cout<<"请输入名字：";
            cin>>key;
            key_ramove(key);                //删除节点，就是删除一个人的信息
            printf_a();
            break;
        case 3:
            cout<<"请输入名字：";
            cin>>key;
            display_menu(find_load(key));   //打印找到节点内的信息，find_load(key)为找节点用的遍历函数
            printf_a();                     //
            break;
        case 4:
            display_list();                 //打印所有节点的名字
            printf_a();
            break;
        case 5:
            display_listfiile();            //把所有节点的信息输入到"address.txt"文件
            break;
        default:
            break;
        }
    }
    return 0;
}
/**************************************************
* 返回类型：void
* 函数作用：打印菜单
***************************************************/
void printf_a()
{
    cout<<"----------------------------------------"<<endl;
    cout<<"- 1.添加  2.删除  3.查找  4.查看通讯录 -"<<endl;
    cout<<"- 5.导出txt文档                        -"<<endl;
    cout<<"----------------------------------------"<<endl;
}
/**************************************************
* 返回类型：Directory*
* 函数作用：新建节点插入，链表
***************************************************/
Directory* load()
{
    Directory *p = new Directory;            //给这个新节点分配空间
    enter(p);

    p->next = head->next;                    //p的下一个指向头指针指向节点的下一个
    head->next = p;                          //头指针指向节点的下一个指向p
    p->prev = head;                          //p的上一个指向指针指向节点的下一个
    p->next->prev = p;
    head = p;                                //头指针指向p


    return p;
}
/**************************************************
* 返回类型：void
* 函数作用：单个节点查找
* 传入参数：名字                 10分
***************************************************/
Directory* find_load(string key_name)
{
    Directory *p;
    p = &pn;
    for(p; p->prev != NULL ;p = p->prev)
    {
        if(p->Name == key_name )
        {
            return p;
        }
    }
    return NULL;
}
/**************************************************
* 返回类型：void
* 函数作用：单个节点删除
* 传入参数：名字               15分
***************************************************/
int key_ramove(string key_name)
{
    Directory *p;                           //定义结构体类型的指针
    p = &pn;
    for(p; p->prev != NULL;p = p->prev)
    {
        if(p->Name == key_name )
        {
            head = pn.prev;
            p->prev->next = p->next;        //p的上一个的下一个指向p的下一个
            p->next->prev = p->prev;        //p的下一个的上一个指向p的上一个
            free(p);                        //释放p的空间
            return 0;                       //删除后，退出函数
        }
    }
    cout<<"没有此人！！！！"<<endl;
    return 0;
}
/**************************************************
* 返回类型：void
* 函数作用：单个节点输入
* 传入参数：Directtory（自己定义的结构体）型指针，   5分
***************************************************/
void enter(Directory *P )
{
    char jubge;                     //用来判断的变量
    string name, mobile;

    cout<<"输入姓名：";
    cin>>name;
    P->Name = name;                 //把输入的字符串放到，当前指针指向的节点

    cout<<"输入电话：";
    cin>>mobile;
    P->Mobile = mobile;             //把输入的字符串放到，当前指针指向的节点

    cout<<"是否完善信息？（Y/N）"<<endl;
    cin>>jubge;

    if(jubge == 'y' ||  jubge == 'Y')
    {
        string wechatnumber;        //微信
        string street;              //街道
        string city;                //城市
        string eip;                 //邮编
        string state;               //国家
        cout<<"微信：";
        cin>>wechatnumber;
        P->Wechatnumber = wechatnumber;

        cout<<"街道：";
        cin>>street;
        P->STREET = street;

        cout<<"城市：";
        cin>>city;
        P->CITY = city;

        cout<<"国家：";
        cin>>state;
        P->STATE = state;
    }else{                          //除了输入y以外都会执行这个
        P->Wechatnumber = "NULL";

        P->STREET = "NULL";

        P->CITY = "NULL";

        P->STATE = "china";
    }
}
/**************************************************
* 返回类型：void
* 函数作用：打印通讯录（所有人名字，逆序）
***************************************************/
void display_list()
{
    Directory *p;   //定义结构体类型的指针
    p = head;       // 让p 等于当前head指针所指的节点
    int i = 1;      //显示序号
    cout<<endl;
    cout<<"*******************************************"<<endl;
    cout<<"               通 讯 录                    "<<endl;
    cout<<"------------------------------------------"<<endl;
    while(p->prev != NULL)                                              //循环，知道p指向节点的prev指针指向NULL
    {
        cout<<" "<<i<<":     "<<p->Name<<endl;                          //打印p指针对应节点的名字
        cout<<"------------------------------------------"<<endl;
        p = p->prev;                                                    //指针指向上一个节点
        i++;
    }
    cout<<"*******************************************"<<endl;
    cout<<endl;
}
void display_listfiile()
{
    Directory *p;                                   //定义结构体类型的指针
    p = &pn;                                       // 让p 等于当前head指针所指的节点
    int i = 1;                                      //显示序号
    ofstream fout("address.txt");                   //打开address.txt文件，没有自动创建

    while(p->prev != NULL)                          //循环，知道p指向节点的prev指针指向NULL
    {
        fout << i <<":" << p->Name <<endl;          //把当前节点的名字输出到address.txt文件
        fout <<"  " << p->Mobile <<endl;
        fout <<"  " << p->Wechatnumber <<endl;
        fout <<"  " << p->STREET <<endl;
        fout <<"  " << p->CITY <<endl;
        fout <<"  " << p->STATE <<endl;
        fout <<endl;
        p = p->prev;                                //指针指向上一个节点
        i++;
    }
    fout.close();                                   //关闭文件流
}
/**************************************************
* 返回类型 Directory
* 函数作用：打印详细信息
***************************************************/
void display_menu(Directory *P)
{
    if(P == NULL)   // 判断 如果P为空，则打印没有这个人
    {
        cout<<"没有此人！！ "<<endl;
    }else{
    cout<<"* * * * * * * * * * * * * * * * * * * * "<<endl;
    cout<<"* 姓名: "<<P->Name<<endl;
    cout<<"* 电话: "<<P->Mobile<<endl;
    cout<<"* 微信: "<<P->Wechatnumber<<endl;
    cout<<"* 街道: "<<P->STREET<<endl;
    cout<<"* 城市: "<<P->CITY<<endl;
    cout<<"* 国家:"<<P->STATE<<endl;
    cout<<"* * * * * * * * * * * * * * * * * * * * "<<endl;
    }
}
