#include<bits/stdc++.h>
using namespace std;

class Array
{
private:
int date[10];
int max;
int min;
float average;
public:
Array(int a[10]);
void process();
void print();
};

Array::Array(int a[10])
{
for(int i=0; i<10; i++)
{
this->date[i] = a[i]; 
}
}

void Array::process()
{
    int all= 0;
    int a = this->date[0];
    for (int k = 0; k < 10; k++)
    {
        if (a < this->date[k])
        {
            a = this->date[k];
        }
}
this->max = a;
for(int l=0; l<10; l++)
{
if(a > this->date[l])
{
a = this->date[l];
}
}
this->min = a;
for( int k=0; k<10; k++)
{
    all =all+this-> date[k];
}

this->average =(all/10);
}

void Array::print()
{
cout<<"最大值为： "<<this->max<<endl;
cout<<"最小值为： "<<this->min<<endl;
cout<<"平均值为： "<<this->average<<endl;
}

int  main()
{

int cou[10];

for(int i=0; i<10; i++)
{
cout<<"请输入第"<<i+1<<"个数字：";
cin>>cou[i];
}

cout<<"输入的十个数字为"<<endl;
for(int j=0; j<10; j++)
{
cout<<cou[j]<<'\t';
}
cout << endl;

Array a(cou);

a.process();
a.print();
return 0;
} 