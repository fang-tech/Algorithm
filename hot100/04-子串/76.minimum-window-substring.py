#
# @lc app=leetcode.cn id=76 lang=python3
#
# [76] 最小覆盖子串
#
from collections import defaultdict

# @lc code=start
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        ans_left,ans_right = 0, int(10**6)
        cnt = defaultdict(int)
        for ch in t:
            cnt[ch] += 1
        def check():
            for x in cnt.values():
                if x > 0:
                    return False
            return True
        l = 0
        for r, ch in enumerate(s):
            cnt[ch] -= 1
            if (check()):
                while check():
                    cnt[s[l]] += 1
                    l += 1
                if ans_right - ans_left > r - l + 1:
                    ans_left, ans_right = l-1, r
        return "" if ans_right == int(10**6) else s[ans_left:ans_right+1]


if __name__ == "__main__":
    s, t = "ADOBECODEBANC", "ABC"
    print(Solution().minWindow(s, t))



# @lc code=end
