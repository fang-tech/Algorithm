#
# @lc app=leetcode.cn id=73 lang=python3
#
# [73] 矩阵置零
#
from typing import *

# @lc code=start
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        m, n = len(matrix), len(matrix[0])
        zero_points = []
        for i, row in enumerate(matrix):
            for j, x in enumerate(row):
                if x == 0:
                    zero_points.append((i, j))

        for i, j in zero_points:
            for x in range(m):
                matrix[x][j] = 0
            for y in range(n):
                matrix[i][y] = 0
# @lc code=end
