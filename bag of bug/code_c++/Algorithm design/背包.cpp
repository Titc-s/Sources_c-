#include <algorithm>
#include <iostream>
using namespace std;
int f[50][50];

int main()
{
    int n, M;
    // n表示有n件物品，M 表示背包载重。
    cout << "input objects number and load of bag:";
    cin >> n >> M;
    int i, j;
    //wi: 第i件产品的重量，pi，第i件产品的收益
    int wi[n + 1], pi[n + 1];
    for (i = 1; i <= n; i++)
    {
        cout << "请输入第" << i << "件产品的重量";
        cin >> wi[i];
    }
    for (i = 1; i <= n; i++)
    {
        cout << "请输入第" << i << "件产品的收益";
        cin >> pi[i];
    }
    for (i = 0; i <= n; i++)
    {
        f[0][i] = 0;
    }
    for (i = 0; i <= M; i++)
    {
        f[i][0] = 0;
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= M; j++)
        {
            if (j >= wi[i])
            {
                f[i][j] = max(f[i - 1][j - wi[i]] + pi[i], f[i - 1][j]);
            }
            else
            {
                f[i][j] = f[i - 1][j];
            }
        }
    }
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= M; j++)
        {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
    cout << f[n][M] << endl;
    return 0;
}
