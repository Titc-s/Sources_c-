#include<bits/stdc++.h>
using namespace std;
template <typename T>void Sort(T tArray[], int len)

{
    int temp;
    for (int i = 0; i < len -i- 1;i++)
    {
        for (int j = 0; j < len - i - 1;j++)
        {
            if (tArray[j]>tArray[j+1])
            {
                temp = tArray[j];
                tArray[j] = tArray[j + 1];
                tArray[j + 1] = temp;
            }
        }
    }
}
int main()
{

}