#include<bits/stdc++.h>
using namespace std;
string s;
double q[20];//储存数字
int main()
{
    while(cin>>s)
    {
	double n=s.size();//字符有多少位    
	int x=0;    
	for(int i=2;i<n;++i)    
	{        
		++x;        
		q[x]=s[i]-'0';//转化为数字    
	}    
	double shi=0;    
	for(int i=1;i<=x;++i)    
	{        
		shi=q[i]*pow(0.125,i)+shi;//计算相加    
	}    
	cout<<s<<"[8]=";    
	printf("%0.45g",shi);        
	cout<<"[10]"<<endl;
	}
	return 0;
}