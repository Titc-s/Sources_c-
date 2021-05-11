#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, b[100] = {0}, i = 0;
    cin >> n;
    while(n--)
    {
        cin >> a;
        while(a>0){
            b[i] = a % 2;
            i++;
            a = a / 2;
        }
        for (; i > 0;i--)
        {
            cout << b[i - 1];
        }
        cout << endl;
    }
    return 0;
}