/*
 * @Author: Titc 1240104681@qq.com
 * @Date: 2023-03-10 10:25:49
 * @LastEditors: Titc 1240104681@qq.com
 * @LastEditTime: 2023-03-10 12:47:10
 * @FilePath: \LeetCodee:\CodeBase\leetcode\66.加一.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {

        int n = digits.size() - 1;
        if (digits[n] != 9)
        {
            digits[n]++;
        }
        else
        {
            int i = n;
            for (i; i >= 0 && digits[i] == 9; i--)
            {
                digits[i] = 0;
            }
            if (i < 0)
            {
                digits[0] = 1;
                digits.push_back(0);
            }
            else
                digits[i]++;
        }
        return digits;
    }
};
// @lc code=end
