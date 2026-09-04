#
# @lc app=leetcode.cn id=3 lang=python3
#
# [3] 无重复字符的最长子串
#
from collections import defaultdict

# @lc code=start
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left = 0
        m = defaultdict(int)
        ans = 0

        for right, ch in enumerate(s):
            m[ch] += 1
            while m[ch] > 1:
                m[s[left]] -= 1
                left += 1
            ans = max(ans, right - left + 1)
        return ans

# @lc code=end

if __name__ == "__main__":
    input = [
        "abcabcbb",
        "bbbbb",
        "pwwkew",
        ""
    ]
    for i in input:
        print(Solution().lengthOfLongestSubstring(i))
