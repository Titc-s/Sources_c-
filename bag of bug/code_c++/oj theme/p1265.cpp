#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, j = 1;
    cin >> n;
    while(n--)
    {
        int number, temp=0;
        double member=0;
        cin >> number;
        for (int i = 1, temp = 0; i <= number;i++){
            member += log10(i * 1.0);

        }
        temp = floor(member) + 1;
        cout << temp << endl;
    }
    return 0;
}