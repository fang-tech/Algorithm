package resolved.dp;
/*
 * @lc app=leetcode.cn id=322 lang=java
 *
 * [322] 零钱兑换
 */

// @lc code=start

import java.util.Arrays;

class Solution {
    public int coinChange(int[] coins, int amount) {
        int len = coins.length;
        int[][] f = new int[len + 1][amount + 1];
        Arrays.fill(f[0], Integer.MAX_VALUE / 2);
        f[0][0] = 0;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j <= amount; j++) {
                if (j < coins[i])
                    f[i+1][j] = f[i][j];
                else
                    f[i+1][j] = Math.min(f[i+1][j-coins[i]] + 1, f[i][j]);
            }
        }
        return f[len][amount] >= Integer.MAX_VALUE / 2 ? -1 : f[len][amount];
    }
}
// @lc code=end

