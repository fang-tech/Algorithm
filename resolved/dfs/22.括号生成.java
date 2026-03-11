/*
 * @lc app=leetcode.cn id=22 lang=java
 *
 * [22] 括号生成
 */

// @lc code=start

import java.util.ArrayList;
import java.util.List;

class Solution {
    private char[] path;
    private List<String> ans = new ArrayList<>();

    /**
     * 选左括号还是右括号,
     * 只有右括号的剩余数量大于左括号的剩余数量才能选
     */
    public List<String> generateParenthesis(int n) {
        path = new char[2*n];
        dfs(n*2, n, n);
        return ans;
    }

    private void dfs(int n, int left, int right) {
        if (left == 0 && right == 0) {
            ans.add(new String(path));
            return ;
        }

        int index = n - left - right;
        if (left > 0) {
            path[index] = '(';
            dfs(n, left-1, right);
        }

        if (right > left) {
            path[index] = ')';
            dfs(n, left, right-1);
        }
    }
}
// @lc code=end

