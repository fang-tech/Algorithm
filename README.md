# Algorithm Solutions

## array

| 题目 | 一句话题解 |
| --- | --- |
| [215.数组中的第k个最大元素](resolved/array/215.数组中的第k个最大元素.java) |  |
| [88.合并两个有序数组](resolved/array/88.合并两个有序数组.java) | 从后往前排, 和合并链表一样的思路, 不过这里nums1剩下的时候可以不用再合并了 |
| [912.排序数组](resolved/array/912.排序数组.java) |  |

## bfs

| 题目 | 一句话题解 |
| --- | --- |
| [102.二叉树的层序遍历](resolved/bfs/102.二叉树的层序遍历.java) | 树的bfs, 注意root可能是null |

## dfs

| 题目 | 一句话题解 |
| --- | --- |
| [200.岛屿数量](resolved/dfs/200.岛屿数量.java) | dfs只用来标记是不是已经访问过了, 遍历所有的节点, 不要使用MAP, 所有的返回条件都放在递归结束的位置做 |
| [46.全排列](resolved/dfs/46.全排列.java) | 每个槽位可以选什么数字, dfs, 记录哪个数字用过了 |

## dp

| 题目 | 一句话题解 |
| --- | --- |
| [53.最大子数组和](resolved/dp/53.最大子数组和.java) | dp, 以这个数字为结尾的最大子数组和 |

## linkedlist

| 题目 | 一句话题解 |
| --- | --- |
| [206.反转链表](resolved/linkedlist/206.反转链表.java) | 三指针, cur是当前要反转的节点 next在反转前移动 |
| [21.合并两个有序链表](resolved/linkedlist/21.合并两个有序链表.java) |  |
| [25.k-个一组翻转链表](resolved/linkedlist/25.k-个一组翻转链表.java) | 翻转每一段链表, 要有dummy, 找到每段链表翻转前的head, head.prev, last, last.next |

## sliding_window

| 题目 | 一句话题解 |
| --- | --- |
| [3.无重复字符的最长子串](resolved/sliding_window/3.无重复字符的最长子串.java) | 使用滑动窗口, 如果某个字符出现的次数大于1, left++, 直到所有字符的出现次数都小等于1, 在这个时刻尝试更新答案 |

## stack

| 题目 | 一句话题解 |
| --- | --- |
| [20.有效的括号](resolved/stack/20.有效的括号.java) | stack |

## string

| 题目 | 一句话题解 |
| --- | --- |
| [5.最长回文子串](resolved/string/5.最长回文子串.java) | 中心扩散, 分成奇偶回文序列两种情况分别遍历 |

## structure

| 题目 | 一句话题解 |
| --- | --- |
| [1.两数之和](resolved/structure/1.两数之和.java) | hashmap<num, index> |
| [146.lru-缓存](resolved/structure/146.lru-缓存.java) | hashmap key: key, val: node node : key, value, prev, next; |

## two_pointers

| 题目 | 一句话题解 |
| --- | --- |
| [15.三数之和](resolved/two_pointers/15.三数之和.java) | 排序, 双指针两数和, 记得去重, 去重是和已经记录过成答案的数据比较 , 比如i是和i-1比较, l是和l-1比较 |
