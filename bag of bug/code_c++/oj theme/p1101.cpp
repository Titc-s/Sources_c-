#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int i = 0;

        while(n!=1)
        {
            if(n%2!=0)
            {
                n = (n * 3 + 1)/2;
                i++;
            }
            else{
                n = n / 2;
                i++;
                }
               
        }
         cout << i << endl;
    }
    return 0;
}