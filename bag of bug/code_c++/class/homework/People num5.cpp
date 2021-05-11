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
    
    return 0;
}
