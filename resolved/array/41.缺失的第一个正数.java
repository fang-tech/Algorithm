package resolved.array;
/*
 * @lc app=leetcode.cn id=41 lang=java
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start

class Solution {
    /**
     * 交换当前元素, 直到当前元素不是范围内元素或者成功替换了,
     * edge case是重复元素, 会导致无限循环
     */
    public int firstMissingPositive(int[] nums) {
        int len = nums.length;
        for (int i = 0; i < len; i++) {
            while (nums[i] >= 1 && nums[i] <= len
                    && nums[i]-1 != i
                    && nums[nums[i]-1] != nums[i]) {
                swap(nums, i, nums[i]-1);
            }
        }
        for (int i = 0; i < len; i++) {
            if (nums[i] != i+1) {
                return i+1;
            }
        }
        return len+1;
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
// @lc code=end