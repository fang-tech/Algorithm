package resolved.dp;
/*
 * @lc app=leetcode.cn id=64 lang=java
 *
 * [64] 最小路径和
 */

// @lc code=start

import java.util.Arrays;

class Solution {
    /**
     * 递推一比一翻译过来即可, 这里缩减了计算图,
     * 让f[j]的值表示f[i+1][j], f[j+1]表示了f[i][j+1]
     */
    public int minPathSum(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int f[] = new int[n+1];
        Arrays.fill(f, Integer.MAX_VALUE);
        f[1] = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                f[j+1] = Math.min(f[j], f[j+1]) + grid[i][j];
            }
        }
        return f[n];
    }
}
// @lc code=end

