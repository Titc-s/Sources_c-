#include <stdio.h>
#include <iostream>
using namespace std;

int PartSort1(int *a, int left, int right)
{
    int key = left;      // 取最左边的元素为key
    while (left < right) // 当左右指针没有相遇
    {
        while (left < right && a[right] >= a[key])
            right--;
        while (left < right && a[left] <= a[key])
            left++;
        // 移动左右指针
        swap(&a[left], &a[right]); // 交换左右指针指向的元素
    }
    swap(&a[key], &a[right]);
    return left;
}
int PartSort3(int *a, int left, int right)
{
    int key = left; // 取最左边为key
    int fast = key + 1;
    int slow = key;
    while (fast <= right) // 判断是否走到尽头
    {
        if (a[fast] < a[key]) // 当快指针指向元素小于key就叫唤

        {
            swap(&a[fast], &a[++slow]); // 交换元素并且慢指针向前走
        }
        fast++; // 快指针向前
    }
    swap(&a[key], &a[slow]);
    return slow;
}