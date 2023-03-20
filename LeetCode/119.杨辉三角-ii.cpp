/*
 * @Author: Titc 1240104681@qq.com
 * @Date: 2023-03-18 10:50:45
 * @LastEditors: Titc 1240104681@qq.com
 * @LastEditTime: 2023-03-18 11:25:18
 * @FilePath: \LeetCodee:\CodeBase\leetcode\119.杨辉三角-ii.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> ans(rowIndex + 1);
        for (int i = 0; i <= rowIndex; i++)
        {
            ans[i] = 1;
            for (int j = i; j > 1; j--)
            {
                ans[j - 1] = ans[j - 2] + ans[j - 1];
            }
        }
        return ans;
    }
};
// @lc code=end
