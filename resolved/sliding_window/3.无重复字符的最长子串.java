/*
 * @lc app=leetcode.cn id=3 lang=java
 *
 * [3] 无重复字符的最长子串
 * 使用滑动窗口, 如果某个字符出现的次数大于1, left++,
 * 直到所有字符的出现次数都小等于1, 在这个时刻尝试更新答案
 */

// @lc code=start
class Solution {

    // 128 ansi字符记录某个字符的出现的次数
    int[] arr = new int[128];

    // n
    public int lengthOfLongestSubstring(String s) {
        int ans = 0;
        char[] charArray = s.toCharArray();
        int len = charArray.length;
        // sliding window
        int left = 0;

        // if check, left++, util check false and update ans
        for (int right = 0; right < len; right++) {
            // 在这个时刻以前是窗口中是没有重复字符的
            arr[charArray[right]]++;
            char cur = charArray[right];
            // 在right右移了以后, 出现了重复的字符
            // 这里出现的重复只会是当前这个字符
            while (arr[cur] > 1) {
                arr[charArray[left++]]--;
            }
            // update ans
            ans = Math.max(ans, right - left + 1);
        }

        return ans;
    }
}
// @lc code=end

