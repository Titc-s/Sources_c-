/*
 * @lc app=leetcode id=4 lang=java
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {

        int m = nums1.length;
        int n = nums2.length;
        if (m > n)
            return findMedianSortedArrays(nums2, nums1);
        int start = 0, end = m;
        int mid = (m + n + 1) / 2;
        int i, j, leftMin, rightMax;
        while (start <= end) {
            i = (start + end) / 2;
            j = mid - i;
            if (i < m && nums2[j - 1] > nums1[i])
                start = i + 1;
            else if (i > 0 && nums2[j] < nums1[i - 1])
                end = i - 1;
            else {
                if (i == 0)
                    leftMin = nums2[j - 1];
                else if (j == 0)
                    leftMin = nums1[i - 1];
                else
                    leftMin = Math.max(nums1[i - 1], nums2[j - 1]);
                if (((m + n) % 2) != 0)
                    return leftMin;

                if (i == m)
                    rightMax = nums2[j];
                else if (j == n)
                    rightMax = nums1[i];
                else
                    rightMax = Math.min(nums1[i], nums2[j]);
                return (leftMin + rightMax) / 2.0;

            }
        }
        return 0;
    }

}
// @lc code=end
