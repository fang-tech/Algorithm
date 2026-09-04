#
# @lc app=leetcode.cn id=560 lang=python3
#
# [560] 和为 K 的子数组
#
from typing import *
from collections import defaultdict

# @lc code=start
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        cnt = 0
        prefix = [0]
        m = defaultdict(int)
        m[0] += 1
        for r, num in enumerate(nums):
            pre = prefix[-1] + num
            prefix.append(pre)
            if pre - k in m.keys():
                cnt += m[pre - k]
            m[pre] += 1
        return cnt

# @lc code=end

if __name__ == "__main__":
    i = [
        {"nums":[1,1,1], "k":2},
        {"nums":[1,2,3], "k":3},
        {"nums":[3,3,3,3], "k":3},
        {"nums":[1], "k":0},
        {"nums":[1, -1, 0], "k":0},
    ]
    o = [
        2,
        2,
        4,
        0,
        3
    ]
    for input, output in zip(i, o):
        print(Solution().subarraySum(**input))
        assert(Solution().subarraySum(**input) == output)
