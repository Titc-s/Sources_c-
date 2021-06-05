#include <iostream>
#include <math.h>
using namespace std;

void input(int &k)
{
    cout << "输入k值" << endl;
    cin >> k;
}

void output(int **a, int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
void Table(int k, int n, int **a)
{
    for (int i = 1; i <= n; i++)
        a[1][i] = i;

    int m = 1; // m为每次填充的起始位置
    for (int s = 1; s <= k; s++)
    {
        n /= 2;
        for (int t = 1; t <= n; t++)
        {
            for (int i = m + 1; i <= 2 * m; i++)
            {
                for (int j = m + 1; j <= 2 * m; j++)
                {
                    a[i][j + (t - 1) * m * 2] = a[i - m][j + (t - 1) * m * 2 - m]; /*右下角的值等于左上角的值 */
                    a[i][j + (t - 1) * m * 2 - m] = a[i - m][j + (t - 1) * m * 2]; /*左下角的值等于右上角的值 */
                }
            }
        }
        m = m * 2;
    }
}

int main()
{
    int k;
    input(k);
    int n = pow(2, k);
    int **a = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        a[i] = new int[n + 1];
    }
    Table(k, n, a);
    cout << "循环赛事日程表为：" << endl;
    output(a, n);
}