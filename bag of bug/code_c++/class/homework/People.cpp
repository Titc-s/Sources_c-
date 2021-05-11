#include<bits/stdc++.h>
using namespace std;
class Date
{
int year;
int month;
int day;
public:
Date(){ }
Date(int y,int m,int d)
{
year=y;
month=m;
day=d;
}
void input()
{
cin>>year>>month>>day;
}
void display()
{
cout<<year<<"年"<<month<<"月"<<day<<"日"<<endl; 
}
};
class People
{
int number;
char sex;
Date birthday;
char ID[18];
public:
People(){}
People(int n,char s,char id[18],int y,int m,int d):birthday(y,m,d)
{
number=n;
sex=s;
strcpy(ID, id);
}
People
(People& P) 
{
     number=P.number; 
     sex=P.sex;
      birthday=P.birthday; 
     strcpy(ID, P.ID);
       }
 ~People() {
 cout<<number<<"号人员已经录入"<<endl; } 
void GetPeople() { cout<<"输入人员编号："; 
cin>>number; 
cout<<"输入人员性别：";
 cin>>sex; cout<<"输入人员生日：";
  birthday.input(); 
  cout<<"输入人员身份证号："; 
cin>>ID;
ID[18] = '\0';
cout<< endl;
}
 void ShowPeople() 
 { 
     cout<<"人员编号："<<number<<endl;
      cout<<"人员性别："<<sex<<endl; 
      cout<<"人员生日："; birthday.display();
       cout<<endl; cout<<"人员身份证号："<<ID<<endl;
        }
         }; 
  int main()
   { People p;
    p.GetPeople();
     p.ShowPeople(); 
     return 0; 
     }

