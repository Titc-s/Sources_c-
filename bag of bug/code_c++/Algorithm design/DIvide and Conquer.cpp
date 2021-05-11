#include<iostream>
#include<cmath>
using namespace std;

// int Algorithm(int a,int b,int c,int d)
// {
//     int x,y;
//     x*y = a*c+100+((a-b)(d-c)+a*c+b*d)*10+b*d;
//     return x*y;
// }

int SIGN(int x)
{
    if(x>=0)
    return 1;
    else return -1;
}
int abs(int x)
{
    if(x>=0)
    return x;
    else 
    return -x;
}

int divideConquer(int X,int Y,int n)
{
    int sign = SIGN(X)*SIGN(Y);
    int x = abs(X);
    int y = abs(Y);
    if(x==0||y==0) return 0;
    else if(n==1)
    return sign*x*y;
    else 
    {
        int A = (int)x/pow(10,(int)(n/2));
        int B = x-A*pow(10,(int)(n/2));
        int C = (int)y/pow(10,(int)(n/2));
        int D = y-C*pow(10,(int)(n/2));
        int AC = divideConquer(A,C,n/2);
        int BD = divideConquer(B,D,n/2);
        int ABCD = divideConquer((A-B),(D-C),n/2)+AC+BD;
        return sign*(AC*pow(10,n)+ABCD*pow(10,(int)n/2)+BD);
    }
}
int main()
{
   int X,Y;  
   cout << "请输入X和Y的值：";
   cin>>X>>Y;
   int XY = divideConquer(X,Y,1);
   cout<<"XY的值为："<<XY;
   return 0;
}