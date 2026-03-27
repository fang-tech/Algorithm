/*
 * @lc app=leetcode.cn id=2946 lang=java
 *
 * [2946] 循环移位后的矩阵相似检查
 */

// @lc code=start
class Solution {
    public boolean areSimilar(int[][] mat, int k) {
        int m = mat.length;
        int n = mat[0].length;
        k %= n;
        boolean left = true;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (left && mat[i][j] == mat[i][(j+n-k)%n]) {
                    left = !left;
                    continue;
                } else if (!left && mat[i][j] == mat[i][(j+k)%n]) {
                    left = !left;
                    continue;
                }
                return false;
            }
        }
        return true;
    }
}
// @lc code=end

