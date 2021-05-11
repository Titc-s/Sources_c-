#include<bits/stdc++.h>
using namespace std;
int fun(int x)
{
    if(x==1)
        return 0;
        else if(x==2)
            return 1;
        else if (x == 3)
            return 2;
            else if(x==4)
                return 2;
                else
                    return (fun(x - 2) + 2 * fun(x - 3) + fun(x - 4));
}
int main()
{
    int n;
    while(cin>>n)
        cout << fun(n) << endl;
    return 0;
}