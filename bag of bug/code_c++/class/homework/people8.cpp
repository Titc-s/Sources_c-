#include<iostream>
#include<string.h>
using namespace std;
class date
{
    public:
        date(int a=0,int b=0,int c=0)
        {
            year=a;
            month=b;
            day=c;
        }
        void set(int y,int m,int d)
        {
            year=y;
            month=m;
            day=d;
        }
          int operator==(const date &a){
            if(day==a.day&&month==a.month&&year==a.year)
                return 1;
            else
                return 0;
          }
        void getdate()
        {
            cout<<year<<"-"<<month<<"-"<<day<<endl;
        }
        private:
            int year,month,day;
};
class People
{
    public:
        People(){};
        People(People&p);
        void setpeople(char a[],char b[],char d[])
        {
            strcpy(number,a);
            strcpy(sex,b);
            strcpy(id,d);

        }
    void setbirthday(date c)
        {
            birthday=c;
        } 
        void get()
        {
        cout<<"number: "<<number<<endl;
        cout<<"sex: "<<sex<<endl;
        cout<<"id: "<<id<<endl;
        } 
        int operator==(const People &a){
            if(!strcmp(number,a.number)&&!strcmp(sex,a.sex)&&(birthday == a.birthday))
                return 1;
                else
                    return 0;
        }
        void operator=(const People &a){
            strcpy(number, a.number);
            strcpy(sex, a.sex);
            birthday = a.birthday;
        }
    
    private:
        char number[11];
        char sex[3];
        date birthday;
        char id[16];
}; 
int main()
{
    date birthday;
    People p;
    int a,b,c;
    cout<<"birthday:"<<endl;
    cin>>a>>b>>c;
    birthday.set(a,b,c);
    char number[7];
    cout<<"number:"<<endl;
    cin>>number;    
    char sex[3];
    cout<<"sex:"<<endl;
    cin>>sex;   
    char id[16];
    cout<<"id:"<<endl;
    cin>>id;
    p.setpeople(number,sex,id);
    p.get();
    birthday.getdate();
    People e;
    e = p;
    e.get();
    cout << (a == b) << endl;

    return 0;
}
