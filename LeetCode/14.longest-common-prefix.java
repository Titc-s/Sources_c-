import java.util.Arrays;

/*
 * @lc app=leetcode id=14 lang=java
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0)
            return "";
        if (strs.length == 1)
            return strs[0];
        int len = strs.length;
        Arrays.sort(strs);
        // 排序
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < strs[0].length(); i++) {
            if (strs[len - 1].charAt(i) == strs[0].charAt(i)) {
                ans.append(strs[0].charAt(i));
            } else
                return ans.toString();
        }

        return ans.toString();
    }
}
// @lc code=end
