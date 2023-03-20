/*
 * @Author: Titc 1240104681@qq.com
 * @Date: 2023-03-08 18:24:17
 * @LastEditors: Titc 1240104681@qq.com
 * @LastEditTime: 2023-03-09 10:26:14
 * @FilePath: \LeetCodee:\CodeBase\leetcode\35.搜索插入位置.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return 0;
        else
        {
            int n = nums.size();
            int left = 0;
            int right = n - 1;
            int ans = n;
            while (left <= right)
            {
                int mid = ((right - left) / 2) + left;
                if (target <= nums[mid])
                {
                    ans = mid;
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            return ans;
        }
    }
};
// @lc code=end
