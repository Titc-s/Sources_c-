#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        double a[n], max = 0, sum = 0;
        for (int i = 0; i < n;i++)
        {
          cin >> a[i];
          if(a[i]>max)
              max = a[i];
          sum += a[i];
        }
        if(max>sum/2)
            cout <<fixed<<setprecision(1)<< sum - max << endl;
            else
                cout <<fixed<<setprecision(1)<< sum / 2 << endl;
    }
    return 0;
}
