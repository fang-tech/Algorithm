package resolved.sliding_window;
/*
 * @lc app=leetcode.cn id=76 lang=java
 *
 * [76] 最小覆盖子串
 */

// @lc code=start

class Solution {
    public String minWindow(String s, String t) {
        int ansLeft = 0, ansRight = Integer.MAX_VALUE;
        int[] cnt = new int[128];
        for (char ch : t.toCharArray()) {
            cnt[ch]++;
        }
        int left = 0;
        for (int right = 0; right < s.length(); right++) {
            char ch = s.charAt(right);
            cnt[ch]--;
            while (check(cnt)) {
                if (ansRight - ansLeft > right - left) {
                    ansLeft = left;
                    ansRight = right;
                }
                cnt[s.charAt(left)]++;
                left++;
            }
        }
        return ansRight != Integer.MAX_VALUE
            ? s.substring(ansLeft, ansRight + 1)
            : "";
    }

    private boolean check(int[] cnt) {
        for (int c : cnt) {
            if (c > 0)
                return false;
        }
        return true;
    }
}
// @lc code=end

