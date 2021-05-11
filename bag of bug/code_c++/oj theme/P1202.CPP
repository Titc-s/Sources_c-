#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[10000], substr[10000];
   
   while( cin >> str >> substr){
    int length=0, max=0;
    length = strlen(str);
    for (int i = 0; i < length;i++)
    {
        if(str[i]>str[max])
            max = i;
    }
    for (int i = 0; i <= max;i++)
    {
        cout << str[i];

    }
    cout << substr;
    for (int i = max + 1; i < length;i++)
    {
        cout << str[i];
    }
    cout << endl;
   }
    return 0;
}