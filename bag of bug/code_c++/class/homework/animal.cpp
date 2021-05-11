#include<bits/stdc++.h>
using namespace std;
class Animal
{
public:
    Animal() { cout << "Animal 构造成功" << endl; }
    ~Animal() { cout << "Animal 析构成功" << endl;}

    int age;
};

class dog:public Animal
{
public:
dog(){ cout << "dog 构造成功" << endl;}
~dog(){ cout << "dog 析构成功" << endl;}
void SetAge()
{
cout<<"输入年龄:";
cin>>age;
}
void ShowAge()
{
cout<<"年龄为:"<<age<<endl;
}
};

int main()
{
dog a;
a.SetAge();
a.ShowAge();
return 0;
} 