//#include "stdafx.h"
#include <iostream>
using namespace std;
double function1(double x);
double function2(int n);
double x;
int main(int argc, char *argv[])
{
    int choose;
    cout << "(1) f1(x)=3x^3+2x^2-1; " << endl;
    cout << "(2) s=1+(1/x)+(1/x^2)+……  (x>1)" << endl;
    cout << "If you want to realize function1,please enter 1;" << endl;
    cout << "If you want to realize function2,please enter 2;" << endl;
    cin >> choose;

    double s = 1, k;
    if (choose == 1)
    {
        cout << "Input a number: " << endl;
        cin >> x;
        cout << "f1(x)= " << function1(x) << endl;
    }

    else
    {
        int n;
        cout << "Input a number which is greater than 1: " << endl;
        cin >> x;

        k = 1 / x;
        while (k > 0.00001)
        {
            k = k / x;
            n++;
        }
        n += 1;
        cout << "s= " << function2(n);
    }
    return 0;
}
double function1(double x)
{
    return (3 * x * x * x + 2 * x * x - 1);
}

double function2(int n)
{
    if (n == 0)
        return 1;
    else
        return (1 / x) * function2(n - 1) + 1;
}
