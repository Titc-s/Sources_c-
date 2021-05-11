#include<bits/stdc++.h>
using namespace std;
int n;

int main()
{
    while(cin >>n)
    {
        int k = 1;
         while(n>k){
    n = n - k;
    k++;
}
if(k%2==0){
    cout << n << "/" << k - n + 1;
    cout << endl;
}
else
{
    cout << k - n + 1 << "/" << n;
    cout << endl;
}
    }
    return 0;
}