/*
 * @Author: Titc 1240104681@qq.com
 * @Date: 2023-03-17 17:40:46
 * @LastEditors: Titc 1240104681@qq.com
 * @LastEditTime: 2023-03-17 23:19:54
 * @FilePath: \LeetCodee:\CodeBase\leetcode\2389.和有限的最长子序列.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=2389 lang=cpp
 *
 * [2389] 和有限的最长子序列
 */

// @lc code=start
class Solution
{
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int q = queries.size();
        vector<int> ps(n + 1), ans(q);
        for (int i = 0; i < n; i++)
        {
            ps[i + 1] = ps[i] + nums[i];
        }
        for (int i = 0; i < q; i++)
        {
            int m = queries[i];
            ans[i] = upper_bound(ps.begin(), ps.end(), m) - ps.begin() - 1;
        }
        return ans;
    }
};
// @lc code=end
