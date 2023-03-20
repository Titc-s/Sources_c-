/*
 * @Author: Titc 1240104681@qq.com
 * @Date: 2023-03-18 11:38:23
 * @LastEditors: Titc 1240104681@qq.com
 * @LastEditTime: 2023-03-18 14:47:41
 * @FilePath: \LeetCodee:\CodeBase\leetcode\121.买卖股票的最佳时机.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 0)
            return 0;
        int max1 = 0, minm = prices[0];
        for (int i = 0; i < prices.size(); i++)
        {
            max1 = max(max1, prices[i] - minm);
            minm = min(minm, prices[i]);
        }
        return max1;
    }
};
// @lc code=end
