/*
 * @lc app=leetcode.cn id=40 lang=java
 *
 * [40] 组合总和 II
 */

// @lc code=start

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    int[] candidates;
    List<Integer> path;
    List<List<Integer>> ans;
    /**
     * 排序 + 选或不选, 这里比较subtle的是重复问题, 假如x = can[i], x' = can[i+1],
     * 选x不选x' 不选x'选x 这样就会导致重复, 为了避免重复, 我们如果不选, 就要跳过所有和当前can相等的can
     */
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        this.ans = new ArrayList<>();
        path = new ArrayList<>();
        this.candidates = candidates;
        Arrays.sort(candidates);
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
        int x = candidates[i];
        path.add(x);
        dfs(i+1, target - x);
        path.remove(path.size()-1);
        i++;
        while (i < candidates.length && candidates[i] == candidates[i-1]) {
            i++;
        }
        dfs(i, target);
    }
}
// @lc code=end

