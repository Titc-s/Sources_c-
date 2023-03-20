#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<int> test1;
	for (int i =0;i<10;i++)
	{
		test1.push_back(i);
		cout << test1[i] <<endl;
	}
	return 0;
}
