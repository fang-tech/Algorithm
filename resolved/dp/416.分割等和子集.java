/*
 * @lc app=leetcode.cn id=416 lang=java
 *
 * [416] 分割等和子集
 */

// @lc code=start

import java.util.Arrays;

class Solution {
    /**
     * 背包问题
     */
    public boolean canPartition(int[] nums) {
        int sum = Arrays.stream(nums).sum();
        if (sum % 2 == 1) return false;
        sum /= 2;
        boolean[][] f = new boolean[nums.length+1][sum+1];
        f[0][0] = true;
        for (int i = 0; i < nums.length; i++) {
            f[i+1][0] = true;
            for (int j = 1; j <= sum; j++) {
                if (j >= nums[i]) {
                    f[i+1][j] = f[i][j - nums[i]];
                }
                f[i+1][j] |= f[i][j];
            }
        }
        return f[nums.length][sum];
    }
}
// @lc code=end

