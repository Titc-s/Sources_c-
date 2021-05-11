#include<bits/stdc++.h>
using namespace std;
const int mod = 9973;
int n, k;
struct Matrix
{
    int arr[12][12];
};
Matrix init, unit;
Matrix Mul(Matrix a,Matrix b)
{
    Matrix c;
    for (int i = 0; i < n;i++)
        for (int j = 0; j < n;j++)
        {
            c.arr[i][j]=0;
            for (int k = 0; k < n;k++)
                c.arr[i][j] = (c.arr[i][j] + a.arr[i][k] * b.arr[k][j] % mod) % mod;
            c.arr[i][j] %= mod;
        }
    return c;
}
Matrix Pow(Matrix a,Matrix b,int x)
{
    while(x)
    {
        if(x&1)
        {
            b = Mul(b, a);

        }
        x >>= 1;
        a = Mul(a, a);
    }
    return b;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for (int i = 0; i < n;i++)
            for (int j = 0; j < n;j++)
            {
                cin >> init.arr[i][j];
                unit.arr[i][j] = init.arr[i][j];
            }
        Matrix res = Pow(init, unit, k - 1);
        int ans = 0;
        for (int i = 0; i < n;i++)
        {
            ans = (ans + res.arr[i][i]) % mod;
          
        }
         printf("%d\n",ans%mod);
    }
    return 0;
}