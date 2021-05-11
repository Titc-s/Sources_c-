#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    long a, b, r, c;
    cin >> n;
    while(n--)
    {
        cin >> a >> b;
        c = a * b;
        do{
            r = a % b;
            a = b;
            b = r;

        } while (r != 0);
        cout << c / a << endl;

    }
    return 0;
}