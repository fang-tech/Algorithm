/*
 * @lc app=leetcode.cn id=39 lang=java
 *
 * [39] 组合总和
 */

// @lc code=start

import java.util.ArrayList;
import java.util.List;

class Solution {
    int[] candidates;
    List<List<Integer>> ans;
    List<Integer> path;

    /**
     * 选或不选的经典题目
     */
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        this.ans = new ArrayList<>();
        this.candidates = candidates;
        this.path = new ArrayList<>();
        dfs(0, target);
        return ans;
    }

    private void dfs(int i, int target) {
        if (target == 0) {
            ans.add(new ArrayList<>(path));
            return ;
        }
        if (target < 0) return ;
        if (i >= candidates.length) return ;
        path.add(candidates[i]);
        dfs(i, target - candidates[i]);
        path.remove(path.size() - 1);
        dfs(i+1, target);
    }
}
// @lc code=end

