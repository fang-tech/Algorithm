/*
 * @lc app=leetcode.cn id=209 lang=java
 *
 * [209] 长度最小的子数组
 */

// @lc code=start

class Solution {
    /**
     * 滑动窗口, 当windowSum >= target的时候记录答案,
     * 然后滑动left到 windowSum < target
     */
    public int minSubArrayLen(int target, int[] nums) {
        int ansLeft = -1, ansRight = Integer.MAX_VALUE / 2;
        int left = 0;
        for (int right = 0; right < nums.length; right++) {
            target -= nums[right];
            if (target <= 0) {
                while (target <= 0) {
                    target += nums[left++];
                }
                if (ansRight - ansLeft > right - left + 1) {
                    ansRight = right;
                    ansLeft = left - 1;
                }
            }
        }
        return ansRight == Integer.MAX_VALUE / 2
                ? 0
                : ansRight - ansLeft + 1;
    }
}
// @lc code=end

