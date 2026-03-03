/*
 * @lc app=leetcode.cn id=15 lang=java
 *
 * [15] 三数之和
 */

// @lc code=start

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    /**
     * 排序, 双指针两数和, 记得去重, 去重是和已经记录过成答案的数据比较
     * , 比如i是和i-1比较, l是和l-1比较
     */
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        int len = nums.length;
        for (int i = 0; i < len - 2; i++) {
            // 去重 i
            if (i > 0 && nums[i-1] == nums[i])
                continue;
            int l = i + 1, r = len - 1;
            int x = nums[i];
            while (l < r) {
                int sum = nums[l] + nums[r];
                if (sum < -x) {
                    l++;
                } else if (sum > -x) {
                    r--;
                } else if (sum == -x) {
                    // 记录答案
                    ans.add(List.of(nums[i], nums[l], nums[r]));
                    // 去重
                    for (l++; l < r && nums[l-1] == nums[l]; l++) ;
                    for (r--; l < r && nums[r+1] == nums[r]; r--) ;
                }
            }
        }
        return ans;
    }
}
// @lc code=end

