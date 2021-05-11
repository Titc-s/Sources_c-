#include<stdio.h>
int main()
{
    int L,M,i,j;
    bool trees[10001];
    for(i=0;i<10001;i++)
    trees[i]=true;
    while(scanf("%d%d",&L,&M)!=EOF){
    for(i=0;i<M;i++){
    int begin,end;
    scanf("%d%d",&begin,&end);
    for(j=begin;j<=end;j++)
    trees[j]=false;
    }
    int count=0;
    for(i=0;i<=L;i++)
    if(trees[i]) count++;
    printf("%d\n",count);}
    return 0;
    
}