package resolved.stack;
/*
 * @lc app=leetcode.cn id=20 lang=java
 *
 * [20] 有效的括号
 */

// @lc code=start

import java.util.ArrayDeque;
import java.util.Deque;

class Solution {
    /**
     * stack
     */
    public boolean isValid(String s) {
        if (s.length() % 2 == 1) return false;

        Deque<Character> st = new ArrayDeque<>();
        char[] charArray = s.toCharArray();
        for (char ch : charArray) {
            switch (ch) {
                case '(':
                case '[':
                case '{':
                    st.push(ch);
                    break;

                case ')':
                    if (st.isEmpty() || st.pop() != '(')
                        return false;
                    break;
                case ']':
                    if (st.isEmpty() || st.pop() != '[')
                        return false;
                    break;
                case '}':
                    if (st.isEmpty() || st.pop() != '{')
                        return false;
                    break;
            }
        }
        return st.isEmpty();
    }
}
// @lc code=end

