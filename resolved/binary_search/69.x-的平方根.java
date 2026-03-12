package resolved.binary_search;
/*
 * @lc app=leetcode.cn id=69 lang=java
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
    /**
     * 二分查找, 注意不能计算mid^2会导致越界, left在开区间的情况下应该从0开始
     */
    public int mySqrt(int x) {
        int left = 0, right = (x == Integer.MAX_VALUE ? x / 2 : x + 1);
        while (left + 1 < right) {
            int mid  = left + (right - left) / 2;
            if (mid <= x / mid) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
}
// @lc code=end

