#
# @lc app=leetcode.cn id=41 lang=python3
#
# [41] 缺失的第一个正数
#
from typing import *

# @lc code=start
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        # [1, len(nums) + 1]
        for i, x in enumerate(nums):
            if x <= 0 or x > len(nums):
                continue
            while nums[x-1] != x:
                nums[i], nums[x-1] = nums[x-1], x
                x = nums[i]
                if x <= 0 or x > len(nums):
                    break

        for i in range(len(nums)):
            if nums[i] != i+1:
                return i+1
        return len(nums) + 1

# @lc code=end

if __name__ == "__main__":
    i = [
        {"nums":[1,2,0]},
        {"nums":[3,4,1,1,1]},
        {"nums":[7,8,9,11,12]},
    ]
    o = [
        3,
        2,
        1
    ]
    for input, output in zip(i, o):
        print(Solution().firstMissingPositive(**input))
        assert(Solution().firstMissingPositive(**input) == output)
