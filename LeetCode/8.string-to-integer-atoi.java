/*
 * @lc app=leetcode id=8 lang=java
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
    public int myAtoi(String s) {
        int index = 0;
        int flag = 1;
        int total = 0;

        if (s.length() == 0)
            return 0;
        // 空字符串，结束。

        while (s.charAt(index) == ' ' && index < s.length() - 1) {
            index++;
            // 空串跳过。
        }
        if (s.charAt(index) == '+' || s.charAt(index) == '-') {
            flag = s.charAt(index) == '+' ? 1 : -1;
            index++;
            // 确定符号
        }
        while (index < s.length()) {
            int digit = s.charAt(index) - '0';
            // 减掉对应的ascll值
            if (digit < 0 || digit > 9)
                break;
            // 若不为数字，退出循环。

            if (Integer.MAX_VALUE / 10 < total || Integer.MAX_VALUE / 10 == total && Integer.MAX_VALUE % 10 < digit) {
                return flag == 1 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }
            total = 10 * total + digit;
            index++;
        }
        return total * flag;

    }
}
// @lc code=end
