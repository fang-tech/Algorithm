/*
 * @lc app=leetcode.cn id=198 lang=java
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
    /**
     * dp, 偷或不偷
     * f[i+1][0] = max(f[i][1], f[i][0]);
     * f[i+1][1] = max(f[i][1], f[i][0] + nums[i]);
     * @param nums
     * @return
     */
    public int rob(int[] nums) {
        int[][] f = new int[nums.length+1][2];
        f[0][0] = 0; f[0][1] = 0;
        for (int i = 0; i < nums.length; i++) {
            f[i+1][0] = Math.max(f[i][1], f[i][0]);
            f[i+1][1] = Math.max(f[i][1], f[i][0] + nums[i]);
        }
        return Math.max(f[nums.length][0], f[nums.length][1]);
    }
}
// @lc code=end

