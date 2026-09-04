#
# @lc app=leetcode.cn id=438 lang=python3
#
# [438] 找到字符串中所有字母异位词
#
from typing import *
from collections import defaultdict

# @lc code=start
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        cnt  = defaultdict(int)
        ans = []
        for ch in p:
            cnt[ch] += 1
        def check():
            for x in cnt.values():
                if x < 0:
                    return False
            return True

        for r, ch in enumerate(s):
            l = r - len(p) + 1
            cnt[ch] -= 1
            if l < 0:
                continue
            else:
                if check():
                    ans.append(l)
                cnt[s[l]] += 1
        return ans


if __name__ == "__main__":
    i = [
        {"s":"cbaebabacd", "p":"abc"},
        {"s":"abab", "p":"ab"},
    ]
    o = [
        [0,6],
        [0,1,2]
    ]

    for input, output in zip(i, o):
        print(Solution().findAnagrams(**input))
# @lc code=end
