#include <iostream>

using namespace std;

void hanoi(int num,char a ,char b,char c)
{
    if (num==1)
    {
        cout<<"第一个盘从"<<a<<"移动到"<<c<<endl;
    }
    else{
        hanoi(num-1,a,c,b);
        cout<<"第"<<num<<"个盘从"<<a<<"移动到"<<c<<endl;
        hanoi(num-1,b,a,c);
    }
}

int main()
{
    hanoi(5,'a','b','c');
}
