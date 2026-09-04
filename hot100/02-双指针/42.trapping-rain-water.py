#
# @lc app=leetcode.cn id=42 lang=python3
#
# [42] 接雨水
#
from typing import *

# @lc code=start
class Solution:
    def trap(self, height: List[int]) -> int:
        ans = 0
        l, r = 0, len(height)-1
        prefix, suffix = height[l], height[r]
        while l <= r:
            if prefix < suffix:
                water = prefix - height[l]
                l += 1
                prefix = max(prefix, height[l])
            else:
                water = suffix - height[r]
                r -= 1
                suffix = max(suffix, height[r])
            ans += max(0, water)
        return ans


if __name__ == "__main__":
    i =  [
        [4,2,0,3,2,5],
        [0,1,0,2,1,0,1,3,2,1,2,1],
        [1,1,1,1,1,1]
        ]

    for row in i :
        print(Solution().trap(row))
# @lc code=end
