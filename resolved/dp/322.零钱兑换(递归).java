package resolved.dp;
/*
 * @lc app=leetcode.cn id=322 lang=java
 *
 * [322] 零钱兑换
 */

// @lc code=start

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    List<Integer> path = new ArrayList<>();
    int[][] m;

    /**
     * DFS 状态定义：dfs(i, j)
     * 表示仅使用前 i 种硬币（下标范围 [0...i]），
     * 刚好凑出总金额为 j 时，所需要的最少硬币数量。
     * 
     * 对于第 i 种硬币，我们可以：
     * 1. 不选它：直接看前 i-1 种硬币，状态转移为 dfs(i-1, j)
     * 2. 选它：因为硬币数量无限，我们还可以继续选第 i 种硬币（下标 i 不变），状态转移为 dfs(i, j - coins[i]) + 1
     */
    public int coinChange(int[] coins, int amount) {
        m = new int[coins.length][amount+1];
        for (int[] arr : m) {
            Arrays.fill(arr, -1);
        }
        int ans = dfs(coins, coins.length - 1, amount);
        return ans >= Integer.MAX_VALUE / 2 ? -1 : ans;
    }

    private int dfs(int[] coins, int i, int amount) {
        if (i < 0) {
            if (amount == 0) return 0;
            return Integer.MAX_VALUE / 2;
        }

        if (m[i][amount] != -1) return m[i][amount];
        // 使用这个coin
        if (coins[i] > amount)  {
            return m[i][amount] = dfs(coins, i-1, amount);
        }
        int use = dfs(coins, i, amount - coins[i]) + 1;

        // 不用这个coin
        int unuse = dfs(coins, i-1, amount);
        return m[i][amount] = Math.min(unuse, use);
    }
}
// @lc code=end
