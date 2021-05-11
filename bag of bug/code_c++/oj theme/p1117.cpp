#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		string a[n],b;
		for(int i=0;i<n;i++)
		cin>>a[i];
		for(int j=0;j<n;j++)
		for(int i=0;i<n-1;i++)
		{
			if(a[i]>a[i+1])
			{
				b=a[i];
				a[i]=a[i+1];
				a[i+1]=b;
			}
		}
		for(int i=0;i<n;i++)
		{
			if(a[i]!="China")
			cout<<a[i]<<endl;
		}
		cout<<"China"<<endl;
	}
	return 0;
}