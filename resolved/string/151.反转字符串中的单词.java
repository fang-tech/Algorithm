package resolved.string;
/*
 * @lc app=leetcode.cn id=151 lang=java
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution {
    /**
     * 提取word, insert到ans的head
     */
    public String reverseWords(String s) {
        StringBuilder ans = new StringBuilder();
        int begin = 0, end = 0;
        int len = s.length();
        while (begin < len) {
            int[] sub = findSubString(s, begin);
            begin = sub[0];
            end = sub[1];
            ans.insert(0, s.substring(begin, end) + " ");
            begin = end;
        }
        return ans.toString().trim();
    }
    private int[] findSubString(String s, int begin) {
        while (begin < s.length() && s.charAt(begin) == ' ') {
            begin++;
        }
        int end = begin;
        while (end < s.length() && s.charAt(end) != ' ') {
            end++;
        }
        return new int[]{begin, end};
    }
}
// @lc code=end

