/*
 * @lc app=leetcode.cn id=213 lang=java
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
    /**
     * 选了第一家, 则问题退化成求[2, n-1)范围的最大值,
     * 不选第一家, 则问题退化成求[1, n)范围的最大值
     * @param nums
     * @return
     */
    public int rob(int[] nums) {
        int len = nums.length;
        return Math.max(
            nums[0] + rob1(nums, 2, len-1),
            rob1(nums, 1, len));
    }

    private int rob1(int[] nums, int start, int end) {
        int f0 = 0, f1 = 0;
        for (int i = start; i < end; i++) {
            int newF = Math.max(f0+nums[i], f1);
            f0 = f1;
            f1 = Math.max(f1, newF);
        }
        return Math.max(f0, f1);
    }
}
// @lc code=end

