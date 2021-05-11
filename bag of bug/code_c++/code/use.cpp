#include<bits/stdc++.h>
using namespace std; 

class Date //日期类 
{ 
private: 
int year; 
int month; 
int day; 
public: 
Date(){} //默认构造 
Date(int y,int m,int d) //带参构造 
{ 
year=y; 
month=m; 
day=d; 
} 
void set() //设置数据函数 
{ 
cin>>year>>month>>day; 
} 
void display() //显示函数 
{ 
cout<<year<<"年"<<month<<"月"<<day<<"日"; 
} 
}; 
class Person //人员类 
{ 
private: 
int num; 
char sex; 
Date birthday; 
char ID[18]; 
public: 
Person(){} //默认构造 
Person(int n,int y,int m,int d,char id[18],char s='m'):birthday(y,m,d) 
{ 
num=n; 
sex=s; 
strcpy(ID,id); 
} //有默认值的带参构造 
Person(Person& p) //拷贝构造 
{ 
num=p.num; 
sex=p.sex; 
birthday=p.birthday; 
strcpy(ID,p.ID); 
} 
void input() //输入函数 
{ 
cout<<"录入数据："<<endl; 
cout<<"编号："; 
cin>>num; 
cout<<"性别(m/f)："; 
cin>>sex; 
cout<<"生日："; 
birthday.set(); 
cout<<"身份证号："; 
cin>>ID; 
ID[18]='\0'; 
cout<<endl; 
} 
void output() //输出函数 
{ 
cout<<"编号："<<num<<endl; 
cout<<"性别："<<sex<<endl; 
cout<<"生日："; 
birthday.display(); 
cout<<endl; 
cout<<"身份证号："<<ID<<endl; 
} 
~Person() //析构函数 
{ 
cout<<" "<<num<<"号人员已经录入"<<endl; 
} 
}; 
int main() 
{ 
Person p1; 
p1.input(); 
p1.output(); 
return 0; 
} 