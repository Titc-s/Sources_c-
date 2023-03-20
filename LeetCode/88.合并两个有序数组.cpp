/*
 * @Author: Titc 1240104681@qq.com
 * @Date: 2022-07-20 09:35:54
 * @LastEditors: Titc 1240104681@qq.com
 * @LastEditTime: 2022-07-20 10:02:36
 * @FilePath: \LeetCodee:\CodeBase\leetcode\88.合并两个有序数组.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        if (nums1.empty())
            i = -1;
        while (i >= 0 && j >= 0 && k >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[k] = nums1[i];
                i--;
            }
            else
            {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        if (i == -1)
        {
            for (int o = 0; o <= j; o++)
            {
                nums1[o] = nums2[o];
            }
        }
    }
};
// @lc code=end
