#include<bits/stdc++.h>
using namespace std;
int main()
{
	int c[10000] = {0};
	int k = 0,carry = 0, x = 1, i;
	char a[10000], b[10000];
	gets(a);
	gets(b);
	int a_len = strlen(a), b_len = strlen(b);
	for (i = a_len - 1; i >= 0;i--){
		for (int j = b_len; j >= 0;j--){
			c[k] = (a[i] - '0') * (b[i] - '0') + c[k]+carry;
			carry = c[k] / 10;
			c[k] %= 10;
			k++;
		}
		c[k] += carry;
		carry = 0;
		k = x;
		x++;
	}
	for (i = 10000; i > 0;i--)
		if(c[i])
			break;
		
	for (int j = i; j >= 0;j--)
			cout << c[j];
	return 0;

}