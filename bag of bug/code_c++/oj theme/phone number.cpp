#include<bits/stdc++.h>
using namespace std;
int main()
{
    string b;
    while ( cin >> b ){
        int len = b.length();
        cout << '6';
        for (int i = 5; i > 0; i--)
        {
            cout << b[len - i];
        }
        cout << endl;

    }
    return 0;
}