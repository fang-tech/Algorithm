/*
 * @lc app=leetcode.cn id=560 lang=java
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start

import java.util.HashMap;
import java.util.Map;

class Solution {
    /**
     * **前缀和 + 枚举**</br>
     * 计算[left, right]子数组和==k的问题能转化成s[right] -s[left] == k的前缀和问题
     * 即计算s[right] - s[left] == k的数量, 这就变成了一个两数之和的问题了.
     * hashmap: key -> right前面的前缀和值 value -> 出现的次数,
     * 要注意等于key==0的边界情况
     */
    public int subarraySum(int[] nums, int k) {
        int ans = 0;
        Map<Integer, Integer> cnt = new HashMap<>(nums.length, 1);
        int s = 0;
        for (int n : nums) {
            cnt.merge(s, 1, Integer::sum);
            s += n;
            ans += cnt.getOrDefault(s - k, 0);
        }

        return ans;
    }
}
// @lc code=end
