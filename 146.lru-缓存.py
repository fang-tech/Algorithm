#
# @lc app=leetcode.cn id=146 lang=python3
#
# [146] LRU 缓存
#
from __future__ import annotations

# @lc code=start
class LRUCache:
    class Node:
        def __init__(self, key: int, value: int, prev:LRUCache.Node | None =None, next:LRUCache.Node | None =None):
            self.key = key
            self.value = value
            self.prev = prev
            self.next = next

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.size = 0
        self.cache: dict[int, LRUCache.Node] = {} # int -> Node
        self.dummy = self.Node(-1, -1)
        self.dummy.prev = self.dummy
        self.dummy.next = self.dummy


    def get(self, key: int) -> int:
        if key not in self.cache.keys():
            return -1
        node = self.cache[key]
        self.del_node(node)
        self.add_to_head(node)
        return node.value

    def put(self, key: int, value: int) -> None:
        node = self.cache.get(key)
        if node != None:
            node.value = value
            self.del_node(node)
            self.add_to_head(node)
            return
        new_node = self.Node(key, value)
        if self.size + 1 > self.capacity:
            tail = self.dummy.prev
            self.del_node(tail)
            del self.cache[tail.key]
            self.size -= 1
        self.add_to_head(new_node)
        self.cache[key] = new_node
        self.size += 1


    def add_to_head(self, node: Node) -> None:
        node.prev = self.dummy
        node.next = self.dummy.next
        self.dummy.next.prev = node
        self.dummy.next = node

    def del_node(self, node: Node) -> None:
        if node == None:
            return
        node.prev.next = node.next
        node.next.prev = node.prev


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
# @lc code=end

