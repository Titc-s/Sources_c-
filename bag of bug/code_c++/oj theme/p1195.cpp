#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, time;
    while(cin >>n)
    {
        int sum = 1;
        for (int i = 1; i < n; i++)
        {
            time = (sum + 1) * 2;
            sum = time;
        }
        cout << sum << endl;
    }
    return 0;
}