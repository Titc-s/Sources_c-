/*
 * @Author: Titc 1240104681@qq.com
 * @Date: 2023-03-16 19:57:33
 * @LastEditors: Titc 1240104681@qq.com
 * @LastEditTime: 2023-03-17 17:31:36
 * @FilePath: \LeetCodee:\CodeBase\leetcode\5.最长回文子串.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @Author: Titc 1240104681@qq.com
 * @Date: 2023-03-16 19:57:33
 * @LastEditors: Titc 1240104681@qq.com
 * @LastEditTime: 2023-03-17 17:28:10
 * @FilePath: \LeetCodee:\CodeBase\leetcode\5.最长回文子串.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n < 2)
        {
            return s;
        }

        int maxLen = 1;
        int begin = 0;
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
        }
        for (int L = 2; L <= n; L++)
        {
            for (int i = 0; i < n; i++)
            {
                int j = L + i - 1;
                if (j >= n)
                {
                    break;
                }
            }
            if (s[i] != s[j])
            {
                dp[i][j] = false;
            }
            else
            {
                if (j - i < 3)
                {
                    dp[i][j] = true;
                }
                else
                {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }
            if (dp[i][j] && j - i + 1 > maxLen)
            {
                maxLen = j - i + 1;
                begin = i;
            }
        }
        return s.substr(begin, maxLen);
    }
};
// @lc code=end
