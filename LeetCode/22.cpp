
#include <bits/stdc++.h>
using namespace std;
int n, m;
bool cmp(int a, int b)
{
	return a > b;
}
int ans;
int w[30];
int have[30];
void dfs(int weight, int begin)
{
	if (ans == 1)
	{
		return;
	}
	if (weight == 0)
	{
		ans = 1;
		return;
	}
	if (abs(weight) > have[begin])
		return; // ̫���� ���ز���
	for (int i = begin; i < n; i++)
	{
		dfs(weight - w[i], i + 1);
		dfs(weight + w[i], i + 1);
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> w[i];
	}
	sort(w, w + n, cmp); // �������
	for (int i = n - 1; i >= 0; i--)
	{
		have[i] = w[i] + have[i + 1];
	}
	int weight;
	while (m--)
	{
		ans = 0;
		cin >> weight;
		dfs(weight, 0);
		if (ans == 1)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}