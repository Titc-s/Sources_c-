#include<iostream>
using namespace std;
#define PI 3.14
class Shape
{
public:
Shape(){}
~Shape(){}
virtual float GetArea()=0;
};
class Circle:public Shape
{
private:
float Round;
public:
Circle(float radius):Round(radius){}
~Circle(){}
float GetArea(){return PI*Round*Round;}
};
class Rectangel:public Shape
{
private:
float Long,Wide;
public:
Rectangel(){}
Rectangel(float len,float width):Long(len),Wide(width){}
~Rectangel() {}
virtual float GetArea(){return Long*Wide;}
};
class Square:public Rectangel
{
private:
float Widelength;
public:
Square(float wl):Widelength(wl){}
~Square(){}
virtual float GetArea(){return Widelength*Widelength;}
};
int main()
{
Square sq(3);
cout<<"正方形面积:"<<sq.GetArea()<<endl;
return 0;
}