/*
 * @Author: Titc 1240104681@qq.com
 * @Date: 2022-08-31 17:33:17
 * @LastEditors: Titc 1240104681@qq.com
 * @LastEditTime: 2022-08-31 17:53:43
 * @FilePath: \LeetCodee:\CodeBase\leetcode\17.电话号码的字母组合.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> combinations;
        if (digits.empty())
        {
            return combinations;
        }
        unordered_map<char, string> phoneMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}};
        string combination;
        backtrack(combinations, phoneMap, digits, 0, combination);
        return combinations;
    }

    void backtrack(vector<string> &combinations, const unordered_map<char, string> &phoneMap, const string &digits, int index, string &combination)
    {

        if (index == digits.length())
        {
            combinations.push_back(combination);
        }
        else
        {
            char digit = digits[index];
            const string &letters = phoneMap.at(digit);
            for (const char &letter : letters)
            {
                combination.push_back(letter);
                backtrack(combinations, phoneMap, digits, index + 1, combination);
                combination.pop_back();
            }
        }
    }
};
// @lc code=end
