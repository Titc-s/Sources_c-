/*
 * @Author: Titc 1240104681@qq.com
 * @Date: 2023-03-12 12:00:57
 * @LastEditors: Titc 1240104681@qq.com
 * @LastEditTime: 2023-03-12 12:07:13
 * @FilePath: \LeetCodee:\CodeBase\leetcode\70.爬楼梯.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution
{
public:
    int climbStairs(int n)
    {
        int p = 0, q = 0, r = 1;
        for (int i = 1; i <= n; i++)
        {
            p = q;
            q = r;
            r = p + q;
        }
        return r;
    }
};
// @lc code=end
