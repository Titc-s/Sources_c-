#include<iostream>
#include<cstring>
#include<algorithm>
#
using namespace std;
int main() {
	char a[101];
	cin.getline(a,sizeof(a));
	int m=strlen(a);
	reverse(a,a+m);
	puts(a);
}
