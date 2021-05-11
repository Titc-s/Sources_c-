 #include<bits/stdc++.h>
using namespace std;
int TwinsInteger(int n)
{
    int i;
    for (i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            break;
    if (i > sqrt(n))
        return 1;
            else
        return 0;
}
int main()
{
    int num;
    while(cin >>num)
    {
        int i, twin, a;
        for (i = num; i >= 2;i--)
        {
            if(TwinsInteger(i)&&TwinsInteger(i+2)){
                twin = i;
                a = i + 2;
                break;
            }
        }
        cout << twin << " " << a << endl;
       
    }
     return 0;
}