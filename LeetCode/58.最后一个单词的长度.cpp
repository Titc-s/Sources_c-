/*
 * @Author: Titc 1240104681@qq.com
 * @Date: 2023-03-11 10:11:35
 * @LastEditors: Titc 1240104681@qq.com
 * @LastEditTime: 2023-03-11 10:31:56
 * @FilePath: \LeetCodee:\CodeBase\leetcode\58.最后一个单词的长度.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int count = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
            {
                if (count == 0)
                    continue;
                break;
            }
            count++;
        }
        return count;
    }
};
// @lc code=end
