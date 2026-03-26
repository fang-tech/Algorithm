package resolved.dp;
/*
 * @lc app=leetcode.cn id=97 lang=java
 *
 * [97] 交错字符串
 */

// @lc code=start

import java.util.Arrays;

class Solution {
    private String s1;
    private String s2;
    private String s3;

    private int[][] m;
    /**
     * |n-m| <= 1是伪条件, 选或不选, dp记录返回
     */
    public boolean isInterleave(String s1, String s2, String s3) {
        if (s1.length() + s2.length() != s3.length()) return false;
        this.s1 = s1;
        this.s2 = s2;
        this.s3 = s3;
        this.m = new int[s1.length()+1][s2.length()+1];
        for (int[] row : m) {
            Arrays.fill(row, -1);
        }
        return dfs(0, 0);
    }

    private boolean dfs(int i1, int i2) {
        int i3 = i1 + i2;
        if (i1 == s1.length() && i2 == s2.length()) return true;

        char ch1 = i1 >= s1.length() ? '0' : s1.charAt(i1);
        char ch2 = i2 >= s2.length() ? '0' : s2.charAt(i2);
        char ch3 = s3.charAt(i3);
        if (m[i1][i2] != -1) {
            return m[i1][i2] == 1;
        }

        boolean ret = false;
        // 选s1
        if (ch1 == ch3) {
            ret |= dfs(i1+1, i2);
        }
        // 选s2
        if (ch2 == ch3) {
            ret |= dfs(i1, i2+1);
        }
        m[i1][i2] = ret ? 1 : 0;
        return ret;
    }
}
// @lc code=end

