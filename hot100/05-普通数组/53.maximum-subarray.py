#
# @lc app=leetcode.cn id=53 lang=python3
#
# [53] 最大子数组和
#
from typing import *

# @lc code=start
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        prefix = [0]
        minimal = 10**5
        ans = -10**5
        for x in nums:
            minimal = min(minimal, prefix[-1])
            prefix.append(prefix[-1] + x)
            ans = max(ans, prefix[-1] - minimal)
        return ans

# @lc code=end
if __name__ == "__main__":
    i = [
        {"nums":[-2,1,-3,4,-1,2,1,-5,4]},
        {"nums":[1]},
        {"nums":[5,4,-1,7,8]},
    ]
    o = [
        6,
        1,
        23,
    ]
    for input, output in zip(i, o):
        print(Solution().maxSubArray(**input))
        assert(Solution().maxSubArray(**input) == output)

