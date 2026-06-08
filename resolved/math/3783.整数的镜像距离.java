package resolved.math;
/*
 * @lc app=leetcode.cn id=3783 lang=java
 *
 * [3783] 整数的镜像距离
 */

// @lc code=start
class Solution {
    public int mirrorDistance(int n) {
        return Math.abs(n - reverse(n));
    }

    private int reverse(int num) {
        int ret = 0;
        while (num > 0) {
            ret = ret  * 10 + num % 10;
            num /= 10;
        }
        return ret;
    }
}
// @lc code=end

