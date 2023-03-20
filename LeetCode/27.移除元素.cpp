/*
 * @Author: Titc 1240104681@qq.com
 * @Date: 2023-03-08 16:46:06
 * @LastEditors: Titc 1240104681@qq.com
 * @LastEditTime: 2023-03-08 17:07:45
 * @FilePath: \LeetCodee:\CodeBase\leetcode\27.移除元素.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int j = 0;
        if (nums.size() == 0)
            return 0;
        else
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] != val)
                {
                    nums[j] = nums[i];
                    j++;
                }
            }
        }
        return j;
    }
};
// @lc code=end
