#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000
int a[MAXN][MAXN];
int main()
{
  int n, x, y, NUM = 0;
 while( cin >> n){
  memset(a,0,sizeof(a));
  x = 0;
  y = n-1;
  a[x][y] = 1;
  NUM = 1;
  while(NUM < n*n)
  {
    while(y+1 < n && a[x][y+1] == 0)
    {
        a[x][++y] = ++NUM;
    }    
    while(x+1 < n && a[x+1][y] == 0)
    {
	   a[++x][y] = ++NUM;
	}
	while(y-1 >= 0 && a[x][y-1] == 0)
	{
       a[x][--y] = ++NUM;
   	}
	while(x-1 >= 0 && a[x-1][y] == 0)
	{
	   a[--x][y] = ++NUM;
	}
  }
   for(x = 0; x < n; x++)
   {
     for(y = 0; y < n-1; y++)
         cout << a[x][y] << " ";
     cout << a[x][y] << endl;

   }
 }

   return 0;
}