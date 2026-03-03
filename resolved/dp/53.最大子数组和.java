/*
 * @lc app=leetcode.cn id=53 lang=java
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
    /**
     * dp, 以这个数字为结尾的最大子数组和
     */
    public int maxSubArray(int[] nums) {
        int f = nums[0];
        int ans = f;
        for (int i = 1; i < nums.length; i++) {
            f = Math.max(f + nums[i], nums[i]);
            ans = Math.max(ans, f);
        }
        return ans;
    }
}
// @lc code=end

