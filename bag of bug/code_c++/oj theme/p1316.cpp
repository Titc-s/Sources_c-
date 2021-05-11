#include <stdio.h>
#include <string.h>

int height[101],leftdp[101],rightdp[101];
int main()
{
int n;
while (scanf("%d",&n)!=EOF)
{
if(n==-1) break;
int i;
memset(leftdp,0,sizeof(leftdp));
for (i=1;i<=n;i++)
{
scanf("%d",&height[i]);

leftdp[i]=1;
}

int j;

for (i=1;i<=n;i++)
{
for (j=i-1;j>=0;j--)
{
if (height[j]<height[i]&&leftdp[i]<leftdp[j]+1)
{
leftdp[i]=leftdp[j]+1;

}
} 
}

memset(rightdp,0,sizeof(rightdp));
for (i=1;i<=n;i++)
{

rightdp[i]=1;
}

for (i=n;i>=1;i--)
{
for (j=i+1;j<=n;j++)
{
if (height[j]<height[i]&&rightdp[i]<rightdp[j]+1)
{
rightdp[i]=rightdp[j]+1;

} 
}
}

int max=0;
for (i=1;i<=n;i++)
{
if (rightdp[i]+leftdp[i]>max)
{
max=rightdp[i]+leftdp[i];
}
}
max--;

printf("%d\n",n-max);
}
return 0;
} 