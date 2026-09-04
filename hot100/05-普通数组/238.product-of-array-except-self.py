#
# @lc app=leetcode.cn id=238 lang=python3
#
# [238] 除了自身以外数组的乘积
#
from typing import *

# @lc code=start
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        answer = []
        n = len(nums)
        prefix, suffix = [1] * (n + 1), [1] * (n + 1)
        for i in range(n):
            prefix[i+1] = prefix[i] * nums[i]
        for i in range(n - 1, -1, -1):
            suffix[i] = suffix[i+1] * nums[i]
        for i in range(len(nums)):
            answer.append(prefix[i] * suffix[i+1])

        return answer

# @lc code=end
if __name__ == "__main__":
    i = [
        {"nums": [1,2,3,4]},
        {"nums": [-1,1,0,-3,3]},
    ]
    o = [
        [24,12,8,6],
        [0,0,9,0,0]
    ]
    for input, output in zip(i, o):
        print(Solution().productExceptSelf(**input))
        assert(Solution().productExceptSelf(**input) == output)