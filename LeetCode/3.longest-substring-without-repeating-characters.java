/*
 * @lc app=leetcode id=3 lang=java
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] array = new int[256];
        for (int i = 0; i < 256; i++)
            array[i] = -1;
        int n = s.length();

        int res = 0; // 最终求得的长度
        int start = 0; // 当前字符串的开始位置
        for (int i = 0; i < n; i++) {
            int index = s.charAt(i);
            start = Math.max(start, array[index] + 1);
            res = Math.max(res, i - start + 1);
            array[index] = i;
        }
        return res;
    }
}
