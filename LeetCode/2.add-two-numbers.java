import javax.management.ListenerNotFoundException;

/*
 * @lc app=leetcode id=2 lang=java
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode() {} ListNode(int val) { this.val = val; } ListNode(int val,
 * ListNode next) { this.val = val; this.next = next; } }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int sum = 0;
        int append = 0;
        int left = 0;
        ListNode l3 = new ListNode(0);
        ListNode result = l3;

        while ((l1 != null) || (l2 != null)) {
            int v1 = l1 != null ? l1.val : 0;
            int v2 = l2 != null ? l2.val : 0;
            // 判断l1,l2是否有数值
            sum = v1 + v2 + append;
            append = sum / 10;
            left = sum % 10;
            ListNode cursor = new ListNode(left);
            result.next = cursor;
            result = cursor;
            if (l1 != null)
                l1 = l1.next;
            if (l2 != null)
                l2 = l2.next;
        }
        if (append > 0) {
            ListNode cursor = new ListNode(append);
            result.next = cursor;
        }
        return l3.next;
    }
}
// @lc code=end
