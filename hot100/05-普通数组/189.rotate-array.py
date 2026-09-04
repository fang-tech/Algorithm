#
# @lc app=leetcode.cn id=189 lang=python3
#
# [189] 轮转数组
#
from typing import *

# @lc code=start
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        k %= len(nums)
        nums[:] = nums[-k:] + nums[0:-k]

# @lc code=end

if __name__ == "__main__":
    i = [
        {"nums": [1,2,3,4,5,6,7], "k":3},
        {"nums": [-1,-100,3,99], "k":2},
        {"nums": [1,2], "k":7}
    ]
    o = [
        [5,6,7,1,2,3,4],
        [3,99,-1,-100],
        [2,1]
    ]
    for input, output in zip(i, o):
        print(Solution().rotate(**input))
        print(input)

