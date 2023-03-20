/*
 * @Author: Titc 1240104681@qq.com
 * @Date: 2022-07-14 14:58:14
 * @LastEditors: Titc 1240104681@qq.com
 * @LastEditTime: 2023-03-07 19:11:44
 * @FilePath: \LeetCodee:\CodeBase\leetcode\1.two-sum.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ret;

        //
        for (int i = 0; i < num.size(); i++)
        {
            for (int j = i + 1; j < num.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
            }
        }
    }
};
// @lc code=end
