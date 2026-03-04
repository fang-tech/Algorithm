package resolved.linkedlist;
/*
 * @lc app=leetcode.cn id=143 lang=java
 *
 * [143] 重排链表
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
     * 获取中间节点, 从中间节点开始反转链表
     * 将两个的链表合并, 需要注意的是两个子链表的末尾都是第二个反转后的链表的tail
     */
    public void reorderList(ListNode head) {
        ListNode mid = middleNode(head);
        ListNode list2 = reverseList(mid);
        ListNode list1 = head;
        while (list2.next != null) {
            ListNode next1 = list1.next;
            ListNode next2 = list2.next;
            list1.next = list2;
            list2.next = next1;
            list1 = next1;
            list2 = next2;
        }
    }

    private ListNode middleNode(ListNode head) {
        ListNode fast = head, slow = head;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }
        return slow;
    }

    private ListNode reverseList(ListNode head) {
        ListNode prev = null, curr = head;
        while (curr != null) {
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
}
// @lc code=end

