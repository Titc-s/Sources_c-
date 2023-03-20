/*
 * @Author: Titc 1240104681@qq.com
 * @Date: 2023-03-12 13:38:27
 * @LastEditors: Titc 1240104681@qq.com
 * @LastEditTime: 2023-03-12 15:14:29
 * @FilePath: \LeetCodee:\CodeBase\leetcode\83.删除排序链表中的重复元素.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
        {
            return head;
        }
        ListNode *cur = head;
        while (cur->next)
        {
            if (cur->val == cur->next->val)
            {
                cur->next = cur->next->next;
            }
            else
                cur = cur->next;
        }
        return head;
    }
};
// @lc code=end
