/*
 * @lc app=leetcode.cn id=516 lang=java
 *
 * [516] 最长回文子序列
 */

// @lc code=start
class Solution {
    char[] str;
    int[][] m;
    /**
     * 区间dp, 从两侧向中间缩减范围, 子序列问题本质上是选或不选,
     * 如果两侧的字母一致, 说明能都选, 状态 -> dfs(i+1, j-1),
     * 如果两侧的字母不一致, 说明不能都选
     */
    public int longestPalindromeSubseq(String s) {
        str = s.toCharArray();
        m = new int[s.length()][s.length()];
        return dfs(0, s.length()-1);
    }

    private int dfs(int i, int j) {
        if (i > j) return 0;
        if (i == j) return 1;
        if (m[i][j] != 0) return m[i][j];
        if (str[i] == str[j]) return m[i][j] = dfs(i+1, j-1) + 2;
        return m[i][j] = Math.max(dfs(i, j-1), dfs(i+1, j));
    }
}
// @lc code=end

