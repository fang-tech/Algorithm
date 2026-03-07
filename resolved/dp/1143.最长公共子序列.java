package resolved.dp;
/*
 * @lc app=leetcode.cn id=1143 lang=java
 *
 * [1143] 最长公共子序列
 */

// @lc code=start

import java.util.Arrays;

class Solution {
    char[] s;
    char[] t;
    int[][] m;

    /**
     * dfs(i, j): word1前i个字符和word2前j个字符之间的最长子序列长度
     * @param text1
     * @param text2
     * @return
     */
    public int longestCommonSubsequence(String text1, String text2) {
        s = text1.toCharArray();
        t = text2.toCharArray();
        m = new int[s.length][t.length];
        for (var arr : m) {
            Arrays.fill(arr, -1);
        }
        return dfs(s.length-1, t.length-1);
    }

    private int dfs(int i, int j) {
        if (i < 0) return 0;
        if (j < 0) return 0;
        if (m[i][j] != -1) return m[i][j];
        if (s[i] == t[j]) return m[i][j] = dfs(i-1, j-1) + 1;
        else return m[i][j] = Math.max(dfs(i, j-1), dfs(i-1, j));
    }
}
// @lc code=end

