#include <cstdlib>
#include <iostream>
#include <string.h>
#include <tchar.h>
#include <vector>

using namespace std;

int weight[5] = {2, 2, 6, 5, 4}; //每个物品的重量
int value[5] = {6, 3, 5, 4, 6};  //每个物品的价值
int C[6][11];                    //保存各种情况能装下物品价值的数组

vector<int> path;

void FindAnswer()
{
    int capacity = 10;
    for (int i = 5; i > 0; --i)
    {
        if (C[i][capacity] > C[i - 1][capacity])
        {
            path.push_back(i);
            capacity -= weight[i - 1];
        }
    }
}

void Package()
{
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 6; ++j)
        {
            if (i == 0)
            {
                //可选物品为0，所以能装的价值只能为0
                C[j][i] = 0;
            }
            else if (j == 0)
            {
                //容量为零，所以能装的价值也是0
                C[j][i] = 0;
            }
            else
            {
                //判断当前容量能放入
                if (i >= weight[j - 1])
                {
                    C[j][i] = max(C[j - 1][i], (C[j - 1][i - weight[j - 1]] + value[j - 1]));
                }
                //如果不能放入，则不放入该物品
                else
                {
                    C[j][i] = C[j - 1][i];
                }
            }
        }
    }
}

int _tmain(int args, TCHAR *argv[])
{
    memset(C, -1, sizeof(C));
    Package();
    FindAnswer();
    return 0;
}