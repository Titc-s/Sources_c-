/*
 * @lc app=leetcode id=13 lang=java
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution {
    public int romanToInt(String s) {
        int sum = 0;
        int num_l = getValue(s.charAt(0));
        for (int i = 1; i < s.length(); i++) {
            int num = getValue(s.charAt(i));
            if (num_l < num)
                sum -= num_l;
            else
                sum += num_l;
            num_l = num;
        }
        int last = getValue(s.charAt(s.length() - 1));
        sum = sum + last;
        return sum;

    }

    private int getValue(char Roman_way) {
        switch (Roman_way) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }
}

// @lc code=end
