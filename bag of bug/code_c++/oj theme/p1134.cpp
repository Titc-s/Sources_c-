#include <iostream>
#include <string.h>
using namespace std;
#define MAX 3000
int main()
{
    int a[MAX];
    int n,i,j;
    int c=0;
    int s;
    while(cin>>n)
    {
   
    memset(a,0,sizeof(a));
    a[0] = 1;
  
    for(i=2;i<=n;i++)
    {
        for(j=0;j<MAX;j++)
        {
            s=a[j]*i+c;
            a[j]=s%10;
            c=s/10;
        }
    }

    for(i=MAX-1;i>=0;i--)
    {
        if(a[i]!=0)
            break;
    }
    for(j=i;j>=0;j--)
    {
        cout<<a[j];  
    }
	 cout<<endl;
	}
}