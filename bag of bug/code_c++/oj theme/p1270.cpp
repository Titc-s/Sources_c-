#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int a[n] , b = 1;
        for (int i = 0; i < n;i++)
            cin >> a[i];
        for (int i = 1; i < n;i++){
            if(a[i]>a[i-1])
                b++;
        }
        cout << b << endl;
    }
    return 0;
}