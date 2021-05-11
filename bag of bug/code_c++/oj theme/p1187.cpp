#include<bits/stdc++.h>
using namespace std;
int Judge(int m)
{
    int i;
    for ( i = 2; i < m;i++)
    if(m%i==0)
      break;
      if((i)>sqrt(m))
          return 1;
          else
         return 0;
}
int main()
{
    int a, i, j;
    while(cin >>a){
        int t = 0;
        for (i = 2; i < a;i++){
            if(a%i==0&&Judge(i)&&Judge(a/i)){
                t = 1;
                break;
            }
        }
        if(t==1)
            cout << "Yes" << endl;
            else
                cout << "No" << endl;
    }
    return 0;
}