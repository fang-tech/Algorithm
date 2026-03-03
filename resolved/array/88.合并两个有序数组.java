/*
 * @lc app=leetcode.cn id=88 lang=java
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
    /**
     * 从后往前排, 和合并链表一样的思路,
     * 不过这里nums1剩下的时候可以不用再合并了
     */
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int cur = nums1.length-1;
        m--;
        n--;
        while (m >= 0 && n >= 0) {
            if (nums1[m] >= nums2[n]) {
                nums1[cur--] = nums1[m--];
            } else {
                nums1[cur--] = nums2[n--];
            }
        }
        while (n >= 0) {
            nums1[cur--] = nums2[n--];
        }
    }
}
// @lc code=end

