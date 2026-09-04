#
# @lc app=leetcode.cn id=56 lang=python3
#
# [56] 合并区间
#
from typing import *

# @lc code=start
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        sorted_intervals = sorted(intervals, key=lambda x: (x[0], x[1]))
        st = []
        for interval in sorted_intervals:
            if st and st[-1][1] >= interval[0]:
                last_pair = st.pop()
                merged_pair = [last_pair[0], max(interval[1], last_pair[1])]
                st.append(merged_pair)
            else:
                st.append(interval)
        return st

# @lc code=end

if __name__ == "__main__":
    i = [
        {"intervals":[[1,3],[1,6],[8,10],[15,18]]},
        {"intervals":[[1,4],[4,5]]},
        {"intervals":[[4,7],[1,4]]},
        {"intervals":[[1,4],[2,3]]},
    ]
    o = [
        [[1,6],[8,10],[15,18]],
        [[1,5]],
        [[1,7]],
        [[1,4]]
    ]
    for input, output in zip(i, o):
        print(Solution().merge(**input))
        assert(Solution().merge(**input) == output)
