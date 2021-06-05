#include<iostream>
using namespace std;

int min(int x, int y)
{
 if (x < y)   return x;
 else   return y;

}

int max(int x, int y)
{
 if (x > y)   return x;
 else   return y;

}

int Find_min(int A[], int left,int right)
{
    int la, ma, ra;
    if(left==right)
    {
        int min;
        min = A[right];
        return min;
    }
    if(right-left ==1)
    {
        la = A[left];
        ra = A[right];
        return (min(la,ra));
    }
    if(right -left > 1)
    {
        ma = (left + right) / 2;
        la = Find_min(A, left, ma);
        ra = Find_min(A, ma, right);
        return (min(la, ra));
    }
}
int Find_max(int A[],int left,int right)
{
      int la, ma, ra;
    if(left==right)
    {
        int max;
        max = A[right];
        return max;
    }
    if(right-left ==1)
    {
        la = A[left];
        ra = A[right];
        return (max(la,ra));
    }
    if(right -left > 1)
    {
        ma = (left + right) / 2;
        la = Find_max(A, left, ma);
        ra = Find_max(A, ma, right);
        return (max(la, ra));
    }
}
int mian()
{
    int A[100];
    int n;
    int min;
    int max;
    cout << "请输入金块数目：";
    cin >> n;
    cout << endl
         << "请按序输入金块重量：" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "第" << i + 1 << "块金块的重量为：";
        cin >> A[i];
        cout << endl;
    }
    max = Find_max(A, 0, n - 1);
    min = Find_min(A, 0, n - 1);
    cout << "最重的金块为第：" << max << "块" << endl;
    cout << "最轻的金块为第：" << min << "块" << endl;
    return 0;
}