#include<bits/stdc++.h>
// 内联：空间换时间；函数内容简单时使用，提高程序效率；2、内联对宏升级
// 声明 定义二选一 inline
#define N 5// 宏定义
using namespace std;
inline int S(int);
int main()
{
    cout << N << endl;

    int result1 = S(5+10);
   // double result2 = S(2.5);
    cout << result1 << endl;
   // cout << result2 << endl;
    return 0;
}
int S (int num)
{
    return num * num;
}