/*
 * @lc app=leetcode.cn id=54 lang=java
 *
 * [54] 螺旋矩阵
 */

// @lc code=start

import java.util.ArrayList;
import java.util.List;

class Solution {
    /**
     * 发现横向和纵向在各自的方向上, 每轮走的步数--,
     * 需要注意起点在(0, -1)
     */
    public List<Integer> spiralOrder(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        List<Integer> ans = new ArrayList<>();
        int hor_step = n;
        int ver_step = m-1;
        int step = 1;
        int x = 0, y = -1;
        while (ans.size() < m * n) {
            // 横向走hor_step
            for (int i = 0; i < hor_step; i++) {
                y += step;
                ans.add(matrix[x][y]);
            }
            // 纵向走ver_step步
            for (int i = 0; i < ver_step; i++) {
                x += step;
                ans.add(matrix[x][y]);
            }
            hor_step--;
            ver_step--;
            step = -step;
        }
        return ans;
    }
}
// @lc code=end

