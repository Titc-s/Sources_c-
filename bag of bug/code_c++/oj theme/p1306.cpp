#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    while(cin>>n>>m)
    {
        int w[n + 1], v[n + 1];
        for (int i = 1; i <= n;i++)
        {
            cin >> w[i] >> v[i];
        }
        int a[m + 1] = {0};
        for (int i = 1; i <= n;i++)
        {
            for (int j = w[i]; j <= m; j++)
            {
                a[j] = max(a[j], a[j - w[i]] + v[i]);
            }
        }
        cout << a[m] << endl;
    }
    return 0;
}