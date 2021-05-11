#include<bits/stdc++.h>
using namespace std;
class Point{
    int x, y;
    public:
        Point(int a = 0, int b = 0):x(a),y(b){}
        friend Point operator+(Point &a,Point &b) { return a.x+b.x, a.y + b.y; }
        friend Point operator-(Point &a,Point &b) { return a.x - b.x, a.y - b.y; }
        friend Point operator++(Point &a) { a.x++, a.y++;
            return Point(a.x, a.y);
        }
        friend Point operator--(Point &a,int) { Point o(a.x, a.y);
            a.x--, a.y--;
             return o;
        }
        void show() { cout << "Point:" << x << " " << y << endl; }
};
int main()
{
    Point m(2, 3), n(4, 5), o, p;
    o = m+n;
    o.show();
    o = m - n;
    o.show();
    ++m;
    m.show();
    n--;
    n.show();
}