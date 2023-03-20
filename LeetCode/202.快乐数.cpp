/*
 * @Author: Titc 1240104681@qq.com
 * @Date: 2022-09-23 17:21:53
 * @LastEditors: Titc 1240104681@qq.com
 * @LastEditTime: 2022-09-23 17:34:05
 * @FilePath: \LeetCodee:\CodeBase\leetcode\202.快乐数.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution
{
public:
    int getNext(int n)
    {
        int totalSum = 0;
        while (n > 0)
        {
            int d = n % 10;
            n = n / 10;
            totalSum += d * d;
        }
        return totalSum;
    }
    bool isHappy(int n)
    {
        int seen = new HashT<>();
        while (n != 1 && !seen.cotains(n))
        {
            seen.add(n);
            n = getNext(n);
        }
        return n == 1;
    }
};
// @lc code=end
