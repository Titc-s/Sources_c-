#include<bits/stdc++.h>
using namespace std;
void show ( double (*)[5], int);
int main()
{
    double powers[3][5] = {
        {45.5, 55, 6, 88, 9},
        {98.2, 69.1, 33, 7, 49},
        {78.2, 58, 5, 12, 8}
        };
        show (powers, 3);
        return 0;
}

void show(double(*arrs)[5],int len)
{
    for (int i = 0;i < len; i++)
    {
        for(int j = 0; j < 5;j ++)
        {
            cout << arrs[i][j] <<"\t";
        }
        cout << endl;

    }

}