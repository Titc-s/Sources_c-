#include<bits/stdc++.h>
using namespace std;
int main()
{
	char a[1000];
	int len;
	cin>>a;
	len=strlen(a);
	for(int i=0;i<len;i++)
	{
		if(a[i]>57&&a[i]<97)
		a[i]+=32;
	}
	for(int i=0;i<len;i++)
	{
		cout<<a[i];
	}
}
