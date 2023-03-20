/*
 * @Author: Titc 1240104681@qq.com
 * @Date: 2023-03-12 10:56:18
 * @LastEditors: Titc 1240104681@qq.com
 * @LastEditTime: 2023-03-12 11:56:30
 * @FilePath: \LeetCodee:\CodeBase\leetcode\69.x-的平方根.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        int l = 0, r = x, ans = -1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid <= x)
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return ans;
    }
};
// @lc code=end
