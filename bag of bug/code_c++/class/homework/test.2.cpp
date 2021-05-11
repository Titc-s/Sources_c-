#include<iostream>
#include<cstring>
using namespace std;

class date{
    public:
        date(int a=0, int b=0, int c=0):day(c), month(b),year(a){}
        void showdata(){
            cout << "出生日期：" << year << '/' << month << '/' << day << endl;
        }
        int operator==(const date &a){
            if(day==a.day&&month==a.month&&year==a.year)
                return 1;
            else
                return 0;
        }
    private: 
        int day;
        int month;
        int year;
};

class people{
    public:
        people(){
            name = new char[10];
            sex = new char[3];
        }
        ~people(){
            delete name;
            delete sex;
        }
        void setdata(){
            char a[10], b[3];
            int c, d, e;
            cout << "请输入信息：";
            cin >> a >> b >> c >> d >> e;
            strcpy(name, a);
            strcpy(sex, b);
            date f(c, d, e);
            birthday = f;
        }
        void showdata(){
            cout << "个人信息：" << name << ' ' << sex << ' ' << endl;
            birthday.showdata();
        }
        int operator==(const people &a){
            if(!strcmp(name, a.name)&&!strcmp(sex, a.sex)&&(birthday==a.birthday))
                return 1;
            else
                return 0;
        }
        void operator=(const people &a){
            strcpy(name, a.name);
            strcpy(sex, a.sex);
            birthday = a.birthday;
        }
    private:
        char *name;
        char *sex;
        date birthday;
};

int main()
{
    people a;
    a.setdata();
    people b = a;
    people c;
    c.setdata();
    a.showdata();
    b.showdata();
    c.showdata();
    cout << (a == b) << endl;
    cout << (a == c) << endl;
}

