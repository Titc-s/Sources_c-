#include<iostream>
using namespace std;

void Init_Graph(int N,int k,int** S,int **C)
{
    int X;
    int i, j;
    int temp = N;
    cout << "输入边的长度，输入1 2 4表示点1 与 2 的长度为4" << endl;
    cin >> i;
    for (int p = 0; p < 4;p++)
    {
        cin >> j;
        cin >> C[i][j];
        cin >> i;
    }
    cout << "驶入每一阶段又哪些点：输入X 1 2 3 表示该阶段有x个点，分别为1，2，3：" << endl;
    for (i = 1; i < k;i++)
    {
        cout << "输入第" << i << "阶段的状态点数：";
        cin>>X;
        cout << "这些点分别为：";
        for (j = 0; j < X;j++)
        {
            cin >> S[i][j];
        }

        
    }
}

 void FMultiGraph()
 {

 }