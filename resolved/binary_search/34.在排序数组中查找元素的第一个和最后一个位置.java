/*
 * @lc app=leetcode.cn id=34 lang=java
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start

class Solution {
    /**
     * 二分搜索, 分别找到第一个 >= target的元素, 和 >= target + 1的元素,
     * 边界条件: 这个元素不存在于数组中, 或者所有的元素都 < target, 导致lower_bound返回nums.length
     * @param nums
     * @param target
     * @return
     */
    public int[] searchRange(int[] nums, int target) {
        int begin = lower_bound(nums, target);
        // 这个元素不存在于数组中
        if (begin == nums.length || nums[begin] != target) return new int[]{-1, -1};
        int end = lower_bound(nums, target+1) - 1;
        return new int[]{begin, end};
    }

    /**
     * 找到的是第一个 >= target的元素的位置
     */
    private int lower_bound(int[] nums, int target) {
        int left = -1, right = nums.length;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return right;
    }
}
// @lc code=end

