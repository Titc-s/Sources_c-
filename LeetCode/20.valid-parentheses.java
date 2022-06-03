import java.util.Stack;

/*
 * @lc app=leetcode id=20 lang=java
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
    public boolean isValid(String s) {
        if (s == null)
            return false;
        int len = s.length();
        Stack<Character> stack = new Stack<>();
        for (int index = 0; index < len; index++) {
            if (stack.isEmpty()) {
                stack.push(s.charAt(index));
            } else {
                if (stack.peek() - s.charAt(index) == -1 || stack.peek() - s.charAt(index) == -2) // ()相差1，[]{}相差2
                    stack.pop();
                else {
                    stack.push(s.charAt(index));
                }
            }
        }
        if (stack.isEmpty())
            return true;
        else {
            return false;
        }
    }
}
// @lc code=end
