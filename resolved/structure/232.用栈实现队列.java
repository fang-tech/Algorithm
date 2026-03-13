/*
 * @lc app=leetcode.cn id=232 lang=java
 *
 * [232] 用栈实现队列
 */

// @lc code=start

import java.util.ArrayDeque;
import java.util.Deque;

class MyQueue {

    Deque<Integer> enqueSt = new ArrayDeque<>();
    Deque<Integer> dequeSt = new ArrayDeque<>();

    /**
     * 维护一个enque队列和deque队列,
     * 在要deque/peek的时候,
     * 如果deque empty, 则把enque中的元素都倒到deque
     * @param x
     */
    public void push(int x) {
        enqueSt.push(x);
    }

    public int pop() {
        if (dequeSt.isEmpty()) {
            while (!enqueSt.isEmpty()) {
                dequeSt.push(enqueSt.pop());
            }
        }
        return dequeSt.pop();
    }

    public int peek() {
        if (dequeSt.isEmpty()) {
            while (!enqueSt.isEmpty()) {
                dequeSt.push(enqueSt.pop());
            }
        }
        return dequeSt.peek();
    }

    public boolean empty() {
        return dequeSt.isEmpty() && enqueSt.isEmpty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */
// @lc code=end

