#
# @lc app=leetcode.cn id=239 lang=python3
#
# [239] 滑动窗口最大值
#
from typing import *
from collections import deque

# @lc code=start
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        de = deque()
        ans = []
        for r, num in enumerate(nums):
            l = r - k + 1
            if de and de[0] < l:
                de.popleft()
            while de and num >= nums[de[-1]]:
                de.pop()
            de.append(r)
            if l < 0:
                continue
            ans.append(nums[de[0]])
        return ans

# @lc code=end

if __name__ == "__main__":
    i = [
        {"nums":[1,3,-1,-3,5,3,6,7], "k":3},
        {"nums":[1], "k":1},
    ]
    o = [
        [3,3,5,5,6,7],
        [1]
    ]
    for input, output in zip(i, o):
        print(Solution().maxSlidingWindow(**input))
        assert(Solution().maxSlidingWindow(**input) == output)
