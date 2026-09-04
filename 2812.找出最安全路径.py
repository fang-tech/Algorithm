#
# @lc app=leetcode.cn id=2812 lang=python3
#
# [2812] 找出最安全路径
#
from typing import List
from collections import deque
import heapq

# @lc code=start
class Solution:
    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        n = len(grid)
        dist = [[-1] * n for _ in range(n)]
        q = []
        for i, row in enumerate(grid):
            for j, x in enumerate(row):
                if x == 1:
                    q.append((i, j))
                    dist[i][j] = 0
        groups = [q]

        # 多源bfs遍历计算出来每个格子的最小安全距离
        while len(q) != 0:
            tmp = q
            q = []
            for i, j in tmp:
                for x, y in (i, j+1), (i, j-1), (i-1, j), (i+1, j):
                    if 0 <= x < n and 0 <= y < n and dist[x][y] == -1:
                        dist[x][y] = len(groups)
                        q.append((x, y))
            groups.append(q)

        # 从大到小枚举距离, 构建并查集, 判断联通
        fa = list(range(n*n))
        def find(x):
            if fa[x] != x:
                fa[x] = find(fa[x])
            return fa[x]

        def union(a, b):
            fa[find(a)] = find(b)

        for d in range(len(groups)-2, 0, -1):
            for i, j in groups[d]:
                for x, y in (i, j+1), (i, j-1), (i-1, j), (i+1, j):
                    if 0 <= x < n and 0 <= y < n and dist[x][y] >= d:
                        union(x*n+y, i*n+j)
            if find(0) == find(n*n-1):
                return d
        return 0


def main():
    grid = [[0,0,1],[0,0,0],[0,0,0]]
    # grid = [[0,0,0,1],[0,0,0,0],[0,0,0,0],[1,0,0,0]]
    ans = Solution().maximumSafenessFactor(grid)
    print(ans)

if __name__ == "__main__":
    main()

# @lc code=end

