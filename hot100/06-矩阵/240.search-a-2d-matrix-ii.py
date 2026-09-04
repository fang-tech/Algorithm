#
# @lc app=leetcode.cn id=240 lang=python3
#
# [240] 搜索二维矩阵 II
#
from typing import *

# @lc code=start
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m, n = len(matrix), len(matrix[0])
        x, y = 0, n - 1
        while True:
            num = matrix[x][y]
            if target == num:
                return True
            elif target < num:
                y -= 1
            else :
                x += 1
            if x > m - 1 or y < 0:
                return False

# @lc code=end
