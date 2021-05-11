#include<bits/stdc++.h>
using namespace std;
class Base{
    public:
        int m, n;
        Base(int x,int y):m(x),n(y){}
};
class Derived:public  Base{
    public:
        int m, k;
        Derived(int i,int j):m(i+1),k(i+1){}
};
int main()
{
    Derived d(1, 2);
    cout << d.m << d.k << d.n;
    return 0;
}