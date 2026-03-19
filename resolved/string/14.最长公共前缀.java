package resolved.string;
/*
 * @lc app=leetcode.cn id=14 lang=java
 *
 * [14] 最长公共前缀
 */

// @lc code=start

class Solution {
    /**
     * 遍历 + 维护公共子串
     */
    public String longestCommonPrefix(String[] strs) {
        String ans = strs[0];
        for (int i = 1; i < strs.length; i++) {
            String str = strs[i];
            int index = pubSubStringIndex(ans, str);
            // 不存在相同的前缀
            if (index == -1) return "";
            ans = ans.substring(0, index);
        }
        return ans;
    }

    private int pubSubStringIndex(String ori, String dest) {
        if (dest.length() < ori.length()) {
            String tmp = dest;
            dest = ori;
            ori = tmp;
        }
        for (int i = 0; i < ori.length(); i++) {
            if (ori.charAt(i) != dest.charAt(i)) {
                return i;
            }
        }
        return ori.length();
    }
}
// @lc code=end

