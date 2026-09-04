#
# @lc app=leetcode.cn id=3 lang=python3
#
# [3] 无重复字符的最长子串
#

# @lc code=start
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans = 0
        cnt = {chr(i):1 for i in range(0, 128)}
        l = 0

        def check():
            for c in cnt.values():
                if c < 0:
                    return False
            return True

        for r in range(len(s)):
            cnt[s[r]] -= 1
            if check():
                ans = max(ans, r-l+1)
            else:
                while not check():
                    cnt[s[l]] += 1
                    l += 1
        return ans

if __name__ == "__main__":
    i = [
        "abcabcbb",
        "bbbbb",
        "pwwkew"
    ]

    o = [
        3,
        1,
        3
    ]

    for a, b in zip(i, o):
        assert(b == Solution().lengthOfLongestSubstring(a))


# @lc code=end
