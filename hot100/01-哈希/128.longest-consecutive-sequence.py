#
# @lc app=leetcode.cn id=128 lang=python3
#
# [128] 最长连续序列
#
from typing import *

# @lc code=start
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        s = set(nums)
        ans = 0
        for x in s:
            l = 0
            # start item
            if x - 1 not in s:
                while x in s:
                    l += 1
                    x += 1
            ans = max(ans, l)
        return ans
# @lc code=end
