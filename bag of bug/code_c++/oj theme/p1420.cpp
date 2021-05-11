#include <bits/stdc++.h>
using namespace std;
#define min(x,y) ((x)<(y)?(x):(y))
int main()
{
    int i,j,n,m,k,flag;
    int ans[116][105];
    while(cin>>n>>m)
    {
        memset(ans,0,sizeof(ans));
        for(i=1;i<=n;++i)
        {
            ans[1][1]=1;
            for(j=min(i-1,m);j>=1&&n-i>=m-j;--j)
            {
                for(k=1;k<=115;++k)
                    ans[k][j]=ans[k][j-1]+j*ans[k][j];
                for(k=1;k<=115;++k)
                    if(ans[k][j]>=10)
                    {
                        ans[k+1][j]+=ans[k][j]/10;
                        ans[k][j]%=10;
                    }
            }
            ans[1][i]=1;
        }
        flag=115;
        for(k=115;k>=0;--k)
            if(ans[k][m]!=0)
            {
                flag=k;
                break;
            }
        if(flag==115)flag=1;
        for(k=flag;k>=1;--k)
            cout<<ans[k][m];
        cout<<endl;
    }
    return 0;
}
