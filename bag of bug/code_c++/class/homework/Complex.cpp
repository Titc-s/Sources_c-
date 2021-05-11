#include<bits/stdc++.h>
using namespace std;

class Complex
{
public:
Complex(float,float);
Complex(float);
void add(Complex &);
void show();

private:
float r;
float i;
};

Complex::Complex(float r1,float i1)
{
r=r1;
i=i1;
}

void Complex::add(Complex &c)
{
r+=c.r;
}

void Complex::show()
{
cout<<r<<'+'<<i<<'i'<<endl;
}

Complex::Complex(float r1)
{
r=r1;
}

int main()
{
Complex c1(3,5);
Complex c2=4.5;
c1.add(c2);
c1.show();
return 0;
} 