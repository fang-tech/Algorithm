/*
 * @lc app=leetcode.cn id=56 lang=java
 *
 * [56] 合并区间
 */

// @lc code=start

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    /**
     * 按照第一个数字升序排序, 然后合
     */
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (p, q) -> p[0] - q[0]);
        List<int[]> ans = new ArrayList<>();
        int[] last = new int[]{intervals[0][0], intervals[0][1]};
        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] <= last[1]) {
                last[1] = Math.max(intervals[i][1], last[1]);
            } else {
                ans.add(last);
                last = intervals[i];
            }
        }
        ans.add(last);
        return ans.toArray(new int[ans.size()][]);
    }
}
// @lc code=end

