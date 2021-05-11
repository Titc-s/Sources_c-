#include<bits/stdc++.h>
using namespace std;
class Circle
{
    public:
        Circle(double);
        ~Circle();

    private:
        double PI = 3.14159;
        double _radius;

    public:
        double get_radius()
        {
            return _radius;
 }
void set_radius(double r) 
{ 
    _radius = r; 
}
void get_area() {
    cout<< "圆的面积为："<< PI * _radius * _radius << endl;
    
     }
};
Circle::Circle(double radius)
{
 _radius = radius;
}
Circle::~Circle()
{

}
int main ()
{
    Circle circle(4);
    circle.get_area();
    return 0;
}