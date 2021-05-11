#include<bits/stdc++.h>
using namespace std;
int prime(int x)
{
    int i;
    for (i = 2; i < sqrt(x);i++)
    if (x%i==0) break;
    if(i>sqrt(x))
        return 1;
        else
            return 0;
}
int main()
{
    int n;
    while(cin>>n)
    {
        int i;
        for (i = 2; i < n;i++)
        if(prime(i)&&prime(n-i))
        {
            cout << i << "+" << n - i << endl;
            break;
        }
    }
    return 0;
}