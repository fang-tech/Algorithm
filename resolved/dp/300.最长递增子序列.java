package resolved.dp;
/*
 * @lc app=leetcode.cn id=300 lang=java
 *
 * [300] 最长递增子序列
 */

// @lc code=start

import java.util.Arrays;

class Solution {
    public int lengthOfLIS(int[] nums) {
        int ans = 1;
        int[] f = new int[nums.length];
        Arrays.fill(f, 1);
        for (int i = 1; i < nums.length; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    f[i] = Math.max(f[i], f[j]+1);
                }
            }
            ans = Math.max(ans, f[i]);
        }
        return ans;
    }
}
// @lc code=end

