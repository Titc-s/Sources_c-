/*
 * @Author: Titc 1240104681@qq.com
 * @Date: 2023-03-16 18:23:37
 * @LastEditors: Titc 1240104681@qq.com
 * @LastEditTime: 2023-03-16 18:39:25
 * @FilePath: \LeetCodee:\CodeBase\leetcode\102.二叉树的层序遍历.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        pre(root, 0, ans);
        return ans;
    }
    void pre(TreeNode *root, int depth, vector<vector<int>> &ans)
    {
        if (!root)
            return;
        if (depth >= ans.size())
            ans.push_back(vector<int>{});
        ans[depth].push_back(root->val);
        pre(root->left, depth + 1, ans);
        pre(root->right, depth + 1, ans);
    }
};
// @lc code=end
