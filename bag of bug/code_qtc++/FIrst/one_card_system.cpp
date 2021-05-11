#include<iostream>
#include<string>
#include<fstream>
#include<stdio.h>
#include"Account.h"
using namespace std;

void Open_system();
void Login_system();
int Create_account();
int Login_account();

Account present_account;

int main()
{
    while(1)
    {
        Open_system();
        int n;
        cin>>n;
        switch(n)
        {
            case 1:
            {
                int a = Create_account();
                if(a == 0)
                {
                    cout<<"用户名已存在，注册失败，请重新选择"<<endl;
                }
                break;
            }
            case 2:
            {
                int a = Login_account();
                if(a == 0)
                {
                    cout<<"用户名不存在，请重新选择"<<endl;
                }
                else if(a == 2)
                {
                    cout<<"密码错误，请重新选择"<<endl;
                }
                else
                {
                    cout<<"登录成功"<<endl;
                    Login_system();
                    int b;
                    cin>>b;
                    switch(b)
                    {
                        case 1:

                        case 2:
                        case 3:
                        case 4:
                            cout<<"已退出系统"<<endl;
                            return 0;
                    }
                }
                break;
            }
            case 3:
            case 4:
                cout<<"已退出系统"<<endl;
                return 0;
        }
    }
    return 0;
}

void Open_system()
{
    cout<<"**************************************"<<endl;
    cout<<"             1.注册账号               "<<endl;
    cout<<"             2.登陆账号               "<<endl;
    cout<<"             3.管理员选项             "<<endl;
    cout<<"             4.退出系统               "<<endl;
    cout<<"**************************************"<<endl;
    cout<<"             请输入：1-4              "<<endl;
}
void Login_system()
{
    cout<<"**************************************"<<endl;
    cout<<"当前用户为:"<<present_account.output_account_number()<<endl;
    cout<<"             1.查询余额               "<<endl;
    cout<<"             2.充值                   "<<endl;
    cout<<"             3.修改密码               "<<endl;
    cout<<"             4.退出系统               "<<endl;
    cout<<"**************************************"<<endl;
    cout<<"             请输入：1-4              "<<endl;
}
int Create_account()
{
    cout<<"请输入账号和密码以完成注册"<<endl;
    cout<<"（账号由数字组成，密码由数字和字母组成）"<<endl;
    Account a;
    a.create_account();
    string name;
    string password;
    string temp;
    name = a.output_account_number();
    password = a.output_account_password();
    int flag = 0;
    ifstream fin("D:\\bag of bug\\code_qtc++\\FIrst\\user_information.txt",ios::in);
    ofstream fout("D:\\bag of bug\\code_qtc++\\FIrst\\user_information.txt",ios::app);
    while(std::getline(fin, temp))
    {
        if(temp == name)flag = 1;
        std::getline(fin, temp);
        std::getline(fin, temp);
    }
    fin.close();
    if(flag)
    {
        return 0;
    }
    else
    {
        cout<<"注册成功,请继续选择你的操作"<<endl;
        fout<<name<<endl;
        fout<<password<<endl;
        fout<<'0'<<endl;
        fout.close();
        return 1;
    }
}
int Login_account()
{
    cout<<"请输入账号和密码来登录"<<endl;
    Account a;
    a.create_account();
    string name;
    string password;
    string temp1;
    string temp2;
    name = a.output_account_number();
    password = a.output_account_password();
    int exist = 0;
    int match = 0;
    ifstream fin("D:\\bag of bug\\code_qtc++\\FIrst\\user_information.txt",ios::in);
    while(std::getline(fin, temp1))
    {
        std::getline(fin, temp2);
        if (name == temp1)
        {
            exist = 1;
            if (password == temp2)
            {
                match = 1;
                break;
            }
        }
        std::getline(fin, temp2);
    }
    fin.close();
    present_account.change_account(name, password);
    if(!exist)return 0;
    else
    {
        if(match)return 1;
        else return 2;
    }
}







