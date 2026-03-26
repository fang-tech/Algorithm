/*
 * @lc app=leetcode.cn id=1262 lang=java
 *
 * [1262] 可被三整除的最大和
 */

// @lc code=start

class Solution {
    /**
     * DP:
     * dfs(i, j): 前i个数字中, 选出来的集合余数为j, 返回集合的最大和
     * nums[i] % 3 == x;
     * 不选这个元素, dfs(i, j) = dfs(i-1, j),
     * 选择这个元素, dfs(i, j) = dfs(i-1, (j-x) mod 3)
     */
    public int maxSumDivThree(int[] nums) {
        int[][] f = new int[nums.length+1][3];
        f[0][1] = f[0][2] = Integer.MIN_VALUE;
        for (int i = 0; i < nums.length; i++) {
            int num = nums[i];
            for (int j = 0; j < 3; j++) {
                f[i+1][j] = Math.max(f[i][j], f[i][(3+j-num%3)%3] + num);
            }
        }
        return f[nums.length][0];
    }
}
// @lc code=end

