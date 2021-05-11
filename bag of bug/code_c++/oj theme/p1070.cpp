#include<bits/stdc++.h>
using namespace std;
void reverse(int *arr,int begin,int end)
{
    int i, j;
    for (i = begin, j = end; i < j;i++,j--)
    {
        int t;
        t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}
void functions(int *arr,int n,int p)
{
        reverse(arr, 0, p - 1);
        reverse(arr, p, n - 1);
        reverse(arr, 0, n - 1);
    }

void display(int *arr,int n)
{
    int i;
    for (i = 0; i < n;i++)
    {
        cout << arr[i] <<" ";
        cout << endl;
    }
  
}
int main()
{
    int num;
    cin >> num;
    int arr[num], change;
    cin >> change;
    for (int i = 0; i < num;i++){
        cin >> arr[i];
    }
    functions(arr, num, change);
    display(arr, num);
    return 0;
}