#
# @lc app=leetcode.cn id=2 lang=python3
#
# [2] 两数相加
#
from typing import *

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
# @lc code=start

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        cin = 0
        head = ListNode()
        p = head
        while l1 or l2 or cin:
            num1 = l1.val if l1 else 0
            num2 = l2.val if l2 else 0
            s = num1 + num2 + cin
            cin = 0
            if s >= 10:
                s -= 10
                cin = 1
            p.next = ListNode(s)
            p = p.next
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
        return head.next

# @lc code=end
