/*
 * @lc app=leetcode.cn id=912 lang=java
 *
 * [912] 排序数组
 */

// @lc code=start

import java.util.Random;

class Solution {
    private static final Random rand = new Random();

    public int[] sortArray(int[] nums) {
        qucikSort(nums, 0, nums.length-1);
        return nums;
    }

    private void qucikSort(int[] nums, int left, int right) {
        if (right <= left) return;
        int i = partition(nums, left, right);
        qucikSort(nums, left, i-1);
        qucikSort(nums, i+1, right);
    }

    // pivot | <= pivot | i ... j | >= pivot
    private int partition(int[] nums, int left, int right) {
        swap(nums, left, left + rand.nextInt(right - left + 1));
        int pivot = nums[left];
        int i = left + 1, j = right;
        while (true) {
            while (i <= j && nums[i] < pivot) {
                i++;
            }
            while (i <= j && nums[j] > pivot) {
                j--;
            }
            if (i >= j)
                break;
            swap(nums, i, j);
            i++;
            j--;
        }
        swap(nums, left, j);
        return j;
    }

    private void swap(int[] nums, int l, int r) {
        int tmp = nums[l];
        nums[l] = nums[r];
        nums[r] = tmp;
    }
}
// @lc code=end

