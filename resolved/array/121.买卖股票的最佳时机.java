package resolved.array;
/*
 * @lc app=leetcode.cn id=121 lang=java
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
    /**
     * 枚举卖出的价格, 维护最小的买入价格
     */
    public int maxProfit(int[] prices) {
        int ans = 0;
        int min = prices[0];
        for (int i = 1; i < prices.length; i++) {
            int x = prices[i];
            // 可以卖出
            if (x > min) {
                ans = Math.max(ans, x - min);
            }
            min = Math.min(min, x);
        }
        return ans;
    }
}
// @lc code=end

