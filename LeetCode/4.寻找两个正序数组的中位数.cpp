/*
 * @Author: Titc 1240104681@qq.com
 * @Date: 2022-07-25 10:50:04
 * @LastEditors: Titc 1240104681@qq.com
 * @LastEditTime: 2022-07-25 11:59:30
 * @FilePath: \LeetCodee:\CodeBase\leetcode\4.寻找两个正序数组的中位数.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution
{
public:
    int getKthElement(const vector<int> &nums1, vector<int> &nums2, int k)
    {
        int m = nums1.size();
        int n = nums2.size();
        int flag1 = 0, flag2 = 0;

        while (true)
        {
            if (flag1 == m)
            {
                return nums2[flag2 + k - 1];
            }
            if (flag2 == n)
            {
                return nums1[flag1 + k - 1];
            }
            if (k == 1)
            {
                return min(nums1[flag1], nums2[flag2]);
            }
            int newflag1 = min(flag1 + k / 2 - 1, m - 1);
            int newflag2 = min(flag2 + k / 2 - 1, n - 1);
            int pivot1 = nums1[newflag1];
            int pivot2 = nums2[newflag2];
            if (pivot1 <= pivot2)
            {
                k -= newflag1 - flag1 + 1;
                flag1 = newflag1 + 1;
            }
            else
            {
                k -= newflag2 - flag2 + 1;
                flag2 = newflag2 + 1;
            }
        }
    }
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int totalLength = nums1.size() + nums2.size();
        if (totalLength % 2 == 1)
        {
            return getKthElement(nums1, nums2, (totalLength + 1) / 2);
        }
        else
        {
            return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
        }
    }
};
// @lc code=end
