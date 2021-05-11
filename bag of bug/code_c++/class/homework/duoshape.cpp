#include<bits/stdc++.h>
using namespace std;
class Shape
{
    float x, y;
    public:
        Shape() { cout << "construct shape" << endl; }
         float GetArea() { return -1; }
         void print() { cout << "-1" << endl; }

};
class Rectangle:public Shape
{
    float wide, len;

public:
    Rectangle(int a = 0, int b = 0): wide(a), len(b) { cout << "construct Rectangle" << endl; }
    float GetArea() { return wide * len; }
    void print() {
        cout << "长:" << len << endl
        << "宽:" << wide << endl
        << "面积:" << GetArea() << endl;
    }
};
class Circle:public  Shape
{
    float radius;
    public:
        Circle(float r = 0) : radius(r) { cout << "construct circle" << endl; }
        float GetArea() { return radius * radius * 3.14; }
        void print() { cout << "半径：" << radius << endl
                            << "面积" << GetArea() << endl; }
};
class Square:public Rectangle
{

    public:
        Square() { cout << "construct square" << endl; }
};
int main()
{
    Shape *sp;
    Circle circle(1);
    Rectangle rec(5, 5);
    sp = &circle;
    cout << sp->GetArea() << endl;
    sp = &rec;
    cout << sp->GetArea() << endl;
}