#include<bits/stdc++.h>
using namespace std;
float PI = 3.14;
class Point{
    float x, y;

public:
    Point(float x = 0.0, float y = 0.0) :x(x), y(y) {}
    void resetP(float newX, float newY)
    {
        x = newX;
        y = newY;
        }
};
class Circle:public Point
{
    float radius;
    

public:
    Circle(float x = 0.0, float y = 0.0,float r=1.0)
    {
      resetP(x, y);
        radius = r;

    }
    void resetC(float newX,float newY,float newR)
    {
      resetP(newX, newY);
        radius = newR;
    }
    double area()
    {
        cout << "所求面积为" << PI * radius * radius << endl;
    }
};
int main()
{
    Circle a(0, 0, 1);
    a.area();
    a.resetC(0, 0, 2);
    a.area();
    return 0;
}