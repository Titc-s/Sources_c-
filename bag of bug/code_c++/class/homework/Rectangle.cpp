#include<bits/stdc++.h>
using namespace std;
class Rectangle
{
     double _x;
     double _y;

 public:
     Rectangle();
     ~Rectangle();
     void SetRectangle(double m_x,double m_y);
     double getX();
     double getY();
     double put(Rectangle&, Rectangle&);
};
Rectangle::Rectangle()
{

}
void Rectangle:: SetRectangle(double m_x,double m_y)
{
    _x = m_x;
    _y = m_y;
}
double Rectangle::getX()
{
    return _x;
}
double Rectangle::getY()
{
    return _y;
}
double Rectangle:: put(Rectangle &rec1, Rectangle &rec2)
{
  
    double area = (rec1.getX() - rec2.getX()) * (rec1.getY() - rec2.getY());
    return area;
}
Rectangle::~Rectangle()
{

}
int main()
{
    Rectangle rec1, rec2;
    double x1, x2, y1, y2;
    cout << "请输入左下方坐标" << endl;
    cin >> x1 >> y1;
    cout << "请输入右上方坐标" << endl;
    cin >> x2>> y2;
    rec1.SetRectangle(x1, y1);
    rec2.SetRectangle(x2, y2);
    double Area= rec1.put(rec1,rec2);

    cout << "面积为" << Area << endl;
    return 0;
}