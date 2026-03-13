package resolved.structure;
/*
 * @lc app=leetcode.cn id=128 lang=java
 *
 * [128] 最长连续序列
 */

// @lc code=start

import java.util.HashSet;
import java.util.Set;

class Solution {
    /**
     * 将元素都存储到集合里面, 遍历集合里面的元素,
     * 如果这个元素是序列的起点(num-1不在set中), 则向后找后续的序列
     */
    public int longestConsecutive(int[] nums) {
        Set<Integer> s = new HashSet<>();
        for (int num : nums) {
            s.add(num);
        }
        int ans = 0;
        for (Integer num : s) {
            if (!s.contains(num-1)) {
                int n = num;
                int len = 1;
                while (s.contains(++n)) {
                    len++;
                }
                ans = Math.max(ans, len);
            }
        }
        return ans;
    }
}
// @lc code=end

