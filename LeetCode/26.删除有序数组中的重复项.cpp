/*
 * @Author: Titc 1240104681@qq.com
 * @Date: 2022-07-20 09:04:50
 * @LastEditors: Titc 1240104681@qq.com
 * @LastEditTime: 2022-07-20 11:05:24
 * @FilePath: \LeetCodee:\CodeBase\leetcode\26.删除有序数组中的重复项.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        // int n = nums.size();
        // if (n == 0)
        //     return 0;
        // int fast = 1, slow = 1;
        // while (fast < n)
        // {
        //     if (nums[fast] != nums[slow - 1])
        //     {
        //         nums[slow] = nums[fast];
        //         slow++;
        //     }
        //     fast++;
        // }
        // return slow;

        if (nums.size() < 2)
            return nums.size();
        int j = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[j] != nums[i])
                nums[++j] = nums[i];
        }
        return ++j;
    }
};
// @lc code=end
