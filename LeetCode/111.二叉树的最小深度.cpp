/*
 * @Author: Titc 1240104681@qq.com
 * @Date: 2023-03-18 17:47:44
 * @LastEditors: Titc 1240104681@qq.com
 * @LastEditTime: 2023-03-18 17:59:22
 * @FilePath: \LeetCodee:\CodeBase\leetcode\111.二叉树的最小深度.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        if (root->left == NULL && root->right == NULL)
            return 1;
        int dep = INT_MAX;
        if (root->left != nullptr)
        {
            dep = min(minDepth(root->left), dep);
        }
        if (root->right != NULL)
        {
            dep = min(minDepth(root->right), dep);
        }
        return dep + 1;
    }
};
// @lc code=end
