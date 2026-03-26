package resolved.array;
/*
 * @lc app=leetcode.cn id=31 lang=java
 *
 * [31] 下一个排列
 */

// @lc code=start

class Solution {
    /**
     * 当找到数字nums[i] < nums[i+1]的时候, 说明存在更大数字,
     * 向前找到第一个 > nums[i]的数字, 将这两个数字交换,
     * 然后在反转剩下的部分, 就是能得到的最小的下一个排列
     */
    public void nextPermutation(int[] nums) {
        int i = nums.length - 1;
        while (i > 0 && nums[i] <= nums[i-1]) {
            i--;
        }
        if (i == 0) {
            reverse(nums, 0, nums.length-1);
            return ;
        }
        int j = nums.length - 1;
        while (nums[j] <= nums[i-1]) {
            j--;
        }
        swap(nums, i-1, j);
        reverse(nums, i, nums.length-1);
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    private void reverse(int[] nums, int i, int j) {
        while (i < j) {
            swap(nums, i, j);
            i++;
            j--;
        }
    }
}
// @lc code=end

