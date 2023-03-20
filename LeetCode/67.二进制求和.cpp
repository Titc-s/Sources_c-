/*
 * @Author: Titc 1240104681@qq.com
 * @Date: 2023-03-11 20:32:39
 * @LastEditors: Titc 1240104681@qq.com
 * @LastEditTime: 2023-03-12 10:54:37
 * @FilePath: \LeetCodee:\CodeBase\leetcode\67.二进制求和.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution
{
public:
    string addBinary(string a, string b)
    {
        string ans;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int n = max(a.size(), b.size()), carry = 0;
        for (int i = 0; i < n; i++)
        {
            carry += i < a.size() ? (a.at(i) == '1') : 0;
            carry += i < b.size() ? (b.at(i) == '1') : 0;
            ans.push_back((carry % 2) ? '1' : '0');
            carry /= 2;
            ;
        }
        if (carry)
        {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
