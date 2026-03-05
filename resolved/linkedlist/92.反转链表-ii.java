/*
 * @lc app=leetcode.cn id=92 lang=java
 *
 * [92] 反转链表 II
 */

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}
// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    /**
     * 创建dummy节点, 记录要反转的区间的前一个节点和下一个节点,
     * 还有反转后的链表的head(prev)和tail(由dummy.next记录)
     * 是按k个反转链表的退阶题目
     */
    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode dummy = new ListNode(-1, head);
        for (int i = 1; i < left; i++) {
            dummy = dummy.next;
        }
        ListNode cur = dummy.next, prev = null;
        // reverse中间的区间的链表
        for (int i = left; i <= right; i++) {
            ListNode nxt = cur.next;
            cur.next = prev;
            prev = cur;
            cur = nxt;
        }
        dummy.next.next = cur;
        dummy.next = prev;

        return left > 1 ? head : prev;
    }
}
// @lc code=end

