#
# @lc app=leetcode.cn id=54 lang=python3
#
# [54] 螺旋矩阵
#
from typing import *

# @lc code=start
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m, n = len(matrix)-1, len(matrix[0])
        ans = []
        direction = 1
        x, y = 0, -1
        while True:
            if n <= 0:
                break
            for i in range(n):
                y += direction
                ans.append(matrix[x][y])
            n -= 1
            if m <= 0:
                break
            for i in range(m):
                x += direction
                ans.append(matrix[x][y])
            direction *= -1
            m -= 1
        return ans


# @lc code=end
if __name__ == "__main__":
    Solution().spiralOrder([[1,2,3],[4,5,6],[7,8,9]])
