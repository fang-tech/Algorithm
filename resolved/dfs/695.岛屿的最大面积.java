package resolved.dfs;
/*
 * @lc app=leetcode.cn id=695 lang=java
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution {
    private int ans = 0;
    /**
     * dfs遍历, dfs返回值是以当前坐标为起点的连通陆地面积
     */
    public int maxAreaOfIsland(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }

    private int dfs(int[][] grid, int x, int y) {
        int m = grid.length, n = grid[0].length;
        if (x >= m || x < 0 || y >= n || y < 0 ||
            grid[x][y] == -1 || grid[x][y] == 0) {
            return 0;
        }
        grid[x][y] = -1;
        int ret = dfs(grid, x+1, y) +
                    dfs(grid, x-1, y) +
                    dfs(grid, x, y+1) +
                    dfs(grid, x, y-1) + 1;
        ans = Math.max(ans, ret);
        return ret;
    }
}
// @lc code=end

