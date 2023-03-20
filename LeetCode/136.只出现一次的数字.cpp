/*
 * @Author: Titc 1240104681@qq.com
 * @Date: 2022-09-23 16:29:43
 * @LastEditors: Titc 1240104681@qq.com
 * @LastEditTime: 2022-09-23 16:39:41
 * @FilePath: \LeetCodee:\CodeBase\leetcode\136.只出现一次的数字.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ret = 0;
        for (auto e : nums)
            ret ^= e;
        return ret;
    }
};
// @lc code=end
