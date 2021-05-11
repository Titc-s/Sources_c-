#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char str[100];
    cin >> str;
    int len = strlen(str);
    for (int i = 0; i < len;i++){
        cout << str[(n + i ) % len];
    }
    cout << endl;
    return 0;
}