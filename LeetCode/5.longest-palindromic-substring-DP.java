/*
 * @lc app=leetcode id=5 lang=java
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
    public String longestPalindrome(String s) {
        if (s.isEmpty())
            return " ";
        int len = s.length();
        if (len == 1)
            return s;
        int longest = 1; // 初始化最长字符串长度
        int start = 0; // 开始位置
        int ans[][] = null;
        ans = new int[1000][1000];
        for (int i = 0; i < len; i++) {
            ans[i][i] = 1;
            if (i < len - 1) {
                if (s.charAt(i) == s.charAt(i + 1)) {
                    ans[i][i + 1] = 1;
                    start = i;
                    longest = 2;
                }
            }
        }
        for (int l = 3; l <= len; l++) {
            for (int i = 0; i + l - 1 < len; i++) {
                int j = l + i - 1;
                if (s.charAt(i) == s.charAt(j) && ans[i + 1][j - 1] == 1) {
                    ans[i][j] = 1;
                    start = i;
                    longest = l;
                }
            }
        }
        return s.substring(start, start + longest);
    }

}
// @lc code=end
