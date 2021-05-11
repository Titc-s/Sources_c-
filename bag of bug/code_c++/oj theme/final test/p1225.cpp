#include<bits/stdc++.h>
using namespace std;
int a[10000] = {0};
void Fnum(int n)
{
    int i;
    int sum, num;
    for (i = 0; i <= n;i++)
    {
        num = i;
        sum = 0;
        while(num>0)
        {
            sum = sum + num % 10;
            num = num / 10;
        }
        sum = sum + i;
        a[sum]++;
    }
}
int main()
{
    int n, i;
    cin >> n;
    Fnum(n);
    for (i = 1; i <= n;i++)
    {
        if(a[i]==0)
            cout << i << endl;
    }
    return 0;
}
