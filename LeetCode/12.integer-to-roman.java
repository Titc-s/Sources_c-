/*
 * @lc app=leetcode id=12 lang=java
 *
 * [12] Integer to Roman
 */

// @lc code=start
class Solution {
    public String intToRoman(int num) {
        String[] thousand = { "", "M", "MM", "MMM" };
        String[] hundred = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
        String[] ten = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
        String[] sin = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };

        String result;
        result = thousand[num / 1000] + hundred[num % 1000 / 100] + ten[num % 100 / 10] + sin[num % 10];
        return result;
    }

}
// @lc code=end
