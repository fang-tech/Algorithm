/*
 * @lc app=leetcode.cn id=394 lang=java
 *
 * [394] 字符串解码
 */

// @lc code=start

import java.util.ArrayDeque;
import java.util.Deque;

class Solution {
    /**
     * 在碰到']'的处理整个模式, 数字的处理, 这里是反序的, 是不是正序读,
     * 要通过位数计算当前数字要乘的10^x, 注意反转
     */
    public String decodeString(String s) {
        StringBuilder ans = new StringBuilder();
        Deque<Character> st = new ArrayDeque<>();
        for (char ch : s.toCharArray()) {
            if (ch != ']') {
                st.push(ch);
                continue ;
            }
            StringBuilder bracket = new StringBuilder();
            char c;
            while ((c = st.pop()) != '[') {
                bracket.append(c);
            }
            int num = 0, p = 0;
            while (!st.isEmpty() && Character.isDigit(st.peek())) {
                num += (st.pop() - '0') * Math.pow(10, p++);
            }
            bracket.reverse();
            for (int i = 0; i < num; i++) {
                for (char b : bracket.toString().toCharArray()) {
                    st.push(b);
                }
            }
        }

        while (!st.isEmpty()) {
            ans.append(st.pop());
        }

        return ans.reverse().toString();
    }
}
// @lc code=end

