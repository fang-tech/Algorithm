/*
 * @lc app=leetcode.cn id=152 lang=java
 *
 * [152] 乘积最大子数组
 */

// @lc code=start

import java.util.Arrays;

class Solution {
    /**
     * 最大子数组和的乘法版本, dp, 计算以nums[i]结尾的最大子数组乘积,
     * 同时记录最大子数组和最小子数组(因为有负数的情况)
     */
    public int maxProduct(int[] nums) {
        int len = nums.length;
        int[] fMax = new int[len];
        int[] fMin = new int[len];
        fMax[0] = fMin[0] = nums[0];
        for (int i = 1; i < len; i++) {
            fMax[i] = Math.max(nums[i], Math.max(fMax[i-1] * nums[i], fMin[i-1] * nums[i]));
            fMin[i] = Math.min(nums[i], Math.min(fMax[i-1] * nums[i], fMin[i-1] * nums[i]));
        }
        return Arrays.stream(fMax).max().getAsInt();
    }
}
// @lc code=end

