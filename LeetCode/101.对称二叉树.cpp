/*
 * @Author: Titc 1240104681@qq.com
 * @Date: 2023-03-14 15:42:16
 * @LastEditors: Titc 1240104681@qq.com
 * @LastEditTime: 2023-03-16 18:20:25
 * @FilePath: \LeetCodee:\CodeBase\leetcode\101.对称二叉树.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool check(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        return p->val == q->val && check(p->right, q->left) && check(p->left, q->right);
    }
    bool isSymmetric(TreeNode *root)
    {
        return check(root, root);
    }
};
// @lc code=end
