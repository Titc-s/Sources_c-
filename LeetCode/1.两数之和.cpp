/*
 * @Author: Titc 1240104681@qq.com
 * @Date: 2022-07-19 16:58:13
 * @LastEditors: Titc 1240104681@qq.com
 * @LastEditTime: 2022-07-19 17:20:35
 * @FilePath: \LeetCodee:\CodeBase\leetcode\1.两数之和.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // vector<int> ret;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     for (int j = i + 1; j < nums.size(); j++)
        //     {
        //         if (nums[i] + nums[j] == target)
        //         {
        //             ret.push_back(i);
        //             ret.push_back(j);
        //         }
        //     }
        // }
        // return ret;
        // Hash Map
        vector<int> ret;
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.count(target - nums[i]) > 0 && i != m[target - nums[i]])
            {
                ret.push_back(i);
                ret.push_back(m[target - nums[i]]);
                break;
            }
        }
        return ret;
    }
};
// @lc code=end
