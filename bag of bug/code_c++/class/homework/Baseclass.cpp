#include<bits/stdc++.h>
using namespace std;
class BaseClass
{
public:
	void fn1() const { cout<<"调用基类函数fn1()"<<endl; }
	void fn2() const { cout<<"调用基类函数fn2()"<<endl; }
};

class DerivedClass :virtual public BaseClass
{
public:
	void fn1() const { cout<<"调用派生类函数fn1()"<<endl; }
	void fn2() const { cout<<"调用派生类函数fn2()"<<endl; }
};

int main()
{
	DerivedClass a;
	a.fn1();
	a.fn2();
	BaseClass *c = &a;
	c->fn1();
	c->fn2();
	DerivedClass *b = &a;
	b->fn1();
	b->fn2();
    return 0;
}
