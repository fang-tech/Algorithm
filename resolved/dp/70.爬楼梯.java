/*
 * @lc app=leetcode.cn id=70 lang=java
 *
 * [70] 爬楼梯
 */

// @lc code=start

class Solution {
    /**
     * 最简单的DP!
     */
    public int climbStairs(int n) {
        int[] f = new int[n+2];
        f[0] = 0;
        f[1] = 1;
        for (int i = 0; i < n; i++) {
            f[i+2] = f[i] + f[i+1];
        }
        return f[n+1];
    }
}
// @lc code=end

