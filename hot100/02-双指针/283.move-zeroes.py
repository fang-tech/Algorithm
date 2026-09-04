#
# @lc app=leetcode.cn id=283 lang=python3
#
# [283] 移动零
#
from typing import *
# @lc code=start
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i0 = 0
        for i in range(len(nums)):
            if nums[i]:
                nums[i0], nums[i] = nums[i], nums[i0]
                i0 += 1

# @lc code=end
