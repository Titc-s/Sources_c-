/*
 * @lc app=leetcode id=9 lang=java
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0)
            return false;
        else {
            int flag, ans = 0, nom = x;
            while (nom != 0) {
                flag = nom % 10;
                ans = ans * 10 + flag;
                nom = nom / 10;
            }
            if (ans != x)
                return false;
            else {
                return true;
            }
        }
    }
}

// @lc code=end
