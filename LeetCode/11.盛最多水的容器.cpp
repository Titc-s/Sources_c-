/*
 * @Author: Titc 1240104681@qq.com
 * @Date: 2022-07-24 10:23:51
 * @LastEditors: Titc 1240104681@qq.com
 * @LastEditTime: 2022-07-24 10:46:00
 * @FilePath: \LeetCodee:\CodeBase\leetcode\11.盛最多水的容器.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        // int size = height.size();
        // int left = 0;
        // int right = size - 1;
        // int ans = 0; // 容量置0
        // while (left < right)
        // {
        //     ans = max(ans, min(height[left],height[right]) * (right - left));
        //     if (height[left] > height[right])
        //         right--;
        //     else
        //         left++;
        // }
        // return ans;

        int ans = 0;
        int left = 0, right = height.size() - 1;
        while (left < right)
        {
            int m = min(height[left], height[right]);
            int temp = m * (right - left);
            ans = max(ans, temp);

            while (height[left] <= m && left < right)
            {
                left++;
            }
            while (height[right] <= m && left < right)
            {
                right--;
            }
        }
        return ans;
    }
};
// @lc code=end
