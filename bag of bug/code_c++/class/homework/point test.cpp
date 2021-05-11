#include"Point.h"
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, y;
    Point test;
    cout << "请输入整数x和y" << endl;
    cin >> x >> y;
    test.set(x, y);
    test.getX();
    test.getY();
    Point copy = test;
    cout << " 拷贝后为" << endl;
    copy.getX();
    copy.getY();
    return 0;
}