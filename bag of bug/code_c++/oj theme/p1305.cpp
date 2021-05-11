#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
bool isprime[40];
bool IfReused[20];
int n;
int ans[20];
void pn(int cnt);
int main(void){
    for(int i = 2; i < 40; i++){
        bool flag = true;
        for(int j = 2; j < i; j++){
            if(i%j==0){
                flag = false;
                break;
            }
        }
        if(flag) isprime[i]=true;
    }
    ans[1] = 1;
    int i = 1;
    while(cin >> n){
        memset(IfReused,0,sizeof(IfReused));
        printf("Case %d:\n",i++);
        pn(2);
        printf("\n");
    }
    return 0;
}
void pn(int cnt){
    if(cnt == n+1){
        for(int i = 1; i <= n; i++){
            if(i==n) printf("%d\n",ans[i]);
            else printf("%d ", ans[i]);
        }
        return;
    }else if(cnt==n){
        for(int i = 2; i <= n; i++){
            if(!IfReused[i] && isprime[i+ans[cnt-1]] && isprime[i+ans[1]]){
                IfReused[i]=1;
                ans[cnt]=i;
                pn(cnt+1);
                IfReused[i]=0;
            }
        }
    }else{
        for(int i = 2; i <= n; i++){
            if(!IfReused[i] && isprime[i+ans[cnt-1]]){
                IfReused[i]=1;
                ans[cnt]=i;
                pn(cnt+1);
                IfReused[i]=0;
            }
        }
    }
}