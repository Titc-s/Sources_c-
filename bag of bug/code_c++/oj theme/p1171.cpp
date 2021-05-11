#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n&&n!=0)
    {
        int i;
        int a[n], b[200] = {0};
        for (i = 0; i < n;i++)
        {
            cin >> a[i];
            b[a[i]]++;
        }
        for (i = 1; i <=100;i++)
        {
            if (b[i]&1)
            {
                cout << "Win" << endl;
                break;
            }
        }
            if ( i>100)
                cout << "Lose" << endl;
        
    }
    return 0;
}