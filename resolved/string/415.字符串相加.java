/*
 * @lc app=leetcode.cn id=415 lang=java
 *
 * [415] 字符串相加
 */

// @lc code=start
class Solution {
    public String addStrings(String num1, String num2) {
        int len1 = num1.length(), len2 = num2.length();
        int i1 = len1 - 1, i2 = len2 - 1;
        char[] s1 = num1.toCharArray();
        char[] s2 = num2.toCharArray();
        StringBuilder ans = new StringBuilder();
        int cin = 0;
        while (i1 >= 0 || i2 >= 0 || cin == 1) {
            int n1 = 0, n2 = 0, sum = 0;
            if (i1 >= 0) {
                n1 = s1[i1] - '0';
                i1--;
            }
            if (i2 >= 0) {
                n2 = s2[i2] - '0';
                i2--;
            }
            sum = n1 + n2 + cin;
            cin = 0;
            if (sum >= 10) {
                sum -= 10;
                cin = 1;
            }
            ans.append(sum);
        }

        return ans.reverse().toString();
    }
}
// @lc code=end

