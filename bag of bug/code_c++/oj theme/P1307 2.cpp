#include<bits/stdc++.h>
using namespace std;
int Num[1000][1000];
int main()
{
    int n;
    while (cin >>n)
    {
        int i, j, Sum = 0;
        for (i = 0; i < n;i++){
            for (j = 0; j <= i;j++){
                cin >> Num[i][j];
            }
        }
        for (i = n - 2; i >= 0;i--){
            for (j = 0; j <= i;j++){
                Sum = Num[i + 1][j];
                if(Sum<Num[i+1][j+1]){
                    Sum = Num[i + 1][j + 1];
                }
                Num[i][j] = Num[i][j] + Sum;
            }
        }
        cout << Num[0][0] << endl;
    }
    return 0;
}