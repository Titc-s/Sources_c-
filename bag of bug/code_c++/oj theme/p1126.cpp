#include<bits/stdc++.h>
#define N 100
using namespace std;
int a[100],n;
void Range(int m){
    int i, jor,temp;
    if(m==n){
        for (int i = 1; i <= m;i++)
            cout << a[i];
        cout << endl;
    }
    for (jor = m; jor <= n;jor++){
       temp=a[jor];
        a[jor] = a[m];
        a[m] =temp;
        Range(m + 1);
       temp = a[jor];
        a[jor] = a[m];
        a[m] =temp;
    }
}
int main(){
    int i;
    while(cin >>n){
        for (i = 1; i <= n;i++)
            a[i] = i;
        Range(1);
    }
    return 0;
}