/*
 * @lc app=leetcode.cn id=3761 lang=java
 *
 * [3761] 镜像对之间最小绝对距离
 */

// @lc code=start

import java.util.HashMap;
import java.util.Map;

class Solution {
    public int minMirrorPairDistance(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        int ans = Integer.MAX_VALUE;
        for (int i = nums.length - 1; i >= 0; i--) {
            int reverseNum = reverse(nums[i]);
            if (map.containsKey(reverseNum)) {
                ans = Math.min(ans, map.get(reverseNum) - i);
            }
            map.put(nums[i], i);
        }
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }

    private int reverse(int num) {
        int ret = 0;
        while (num > 0) {
            ret = ret * 10 + num % 10;
            num /= 10;
        }
        return ret;
    }
}
// @lc code=end
