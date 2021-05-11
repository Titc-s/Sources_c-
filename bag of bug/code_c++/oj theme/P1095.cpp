#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int i, sum = 0, max = 0, min = 200, m = 0;
        double average;
        while(cin >> i &&i != -1)
        {
            m++;
            if (i>max){
                max = i;
            }
            if(i<min){
                min = i;
            }
            sum += i;
        }
        average = (float)sum / m;
        cout << m << endl
             << max << endl
             << min << endl
             <<fixed<<setprecision(1)<< average << endl;
    }
    return 0;
}