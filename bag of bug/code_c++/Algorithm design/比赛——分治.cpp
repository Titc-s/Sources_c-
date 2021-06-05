#include<iostream>
#include<math.h>
using namespace std;
int n = 8, k = 3;
int a[8][8];
/*
选手数：n=2k
k =操作次数


*/

void  Init(int n, int *a[])
{
    for (int i = 0; i < n;i++)
    {
        a[0][i] = i;
    }

}
void change(int n, int k, int *a[])
{
    int Num = n;
    for (int i = 0; i < k;i++)
    {
        Num = Num / 2;
        for (int j = 0; j < Num;j++)
        
    }
}