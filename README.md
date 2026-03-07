# Algorithm Solutions

## array

| 题目 | 一句话题解 |
| --- | --- |
| [215.数组中的第k个最大元素](resolved/array/215.数组中的第k个最大元素.java) |  |
| [54.螺旋矩阵](resolved/array/54.螺旋矩阵.java) | 发现横向和纵向在各自的方向上, 每轮走的步数--, 需要注意起点在(0, -1) |
| [56.合并区间](resolved/array/56.合并区间.java) | 按照第一个数字升序排序, 然后合 |
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
| [1143.最长公共子序列](resolved/dp/1143.最长公共子序列.java) | dfs(i, j): word1前i个字符和word2前j个字符之间的最长子序列长度 @param text1 @param text2 @return |
| [300.最长递增子序列](resolved/dp/300.最长递增子序列.java) |  |
| [53.最大子数组和](resolved/dp/53.最大子数组和.java) | dp, 以这个数字为结尾的最大子数组和 |
| [72.编辑距离(递归)](resolved/dp/72.编辑距离(递归).java) | 思路和递推版一致, dfs(i,j): word1前i个字符被转化成word2前j个字符需要的最少步数 递归的返回条件分别是记忆化搜索, i/j越界 |
| [72.编辑距离(递推)](resolved/dp/72.编辑距离(递推).java) | 递推版本: f[i+1][j+1] word1前i+1个字符转化成word2前j+1个字符所需的最小操作数 操作都只对word1操作 插入操作: 插入的字符将j+1给抵消掉了, 所以情况变成了f[i+1][j]+1 删除操作: 删除了一个字符, i+1被删了, f[i][j+1]+1 修改操作: i+1和j+1都被抵消掉了 |

## linkedlist

| 题目 | 一句话题解 |
| --- | --- |
| [143.重排链表](resolved/linkedlist/143.重排链表.java) | 获取中间节点, 从中间节点开始反转链表 将两个的链表合并, 需要注意的是两个子链表的末尾都是第二个反转后的链表的tail |
| [206.反转链表](resolved/linkedlist/206.反转链表.java) | 三指针, cur是当前要反转的节点 next在反转前移动 |
| [21.合并两个有序链表](resolved/linkedlist/21.合并两个有序链表.java) |  |
| [25.k-个一组翻转链表](resolved/linkedlist/25.k-个一组翻转链表.java) | 翻转每一段链表, 要有dummy, 找到每段链表翻转前的head, head.prev, last, last.next |
| [82.删除排序链表中的重复元素-ii](resolved/linkedlist/82.删除排序链表中的重复元素-ii.java) | 如果cur的下两个节点都存在, 并且两个节点的值都相同, 则开始删除和cur.next值相同的节点, 否则cur向前一步 @param head @return |
| [92.反转链表-ii](resolved/linkedlist/92.反转链表-ii.java) | 创建dummy节点, 记录要反转的区间的前一个节点和下一个节点, 还有反转后的链表的head(prev)和tail(由dummy.next记录) 是按k个反转链表的退阶题目 |

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
| [165.比较版本号](resolved/string/165.比较版本号.java) | 从版本号中提取数字, 默认是0, 直到两个字符串都匹配完了, 仍然没有找到更大的, 则返回0(循环外) |
| [32.最长有效括号](resolved/string/32.最长有效括号.java) | list里面存的是没有匹配的'('的索引, 那么每次匹配的到的时候, 就可以通过(i - 最近的没有匹配到的'('的index), 来计算得到当前的连续括号长度, 初始化的时候stack里面存一个-1来作为哨兵 @param s @return |
| [415.字符串相加](resolved/string/415.字符串相加.java) |  |
| [5.最长回文子串](resolved/string/5.最长回文子串.java) | 中心扩散, 分成奇偶回文序列两种情况分别遍历 |

## structure

| 题目 | 一句话题解 |
| --- | --- |
| [1.两数之和](resolved/structure/1.两数之和.java) | hashmap<num, index> |
| [146.lru-缓存](resolved/structure/146.lru-缓存.java) | hashmap key: key, val: node node : key, value, prev, next; |

## tree

| 题目 | 一句话题解 |
| --- | --- |
| [236.二叉树的最近公共祖先](resolved/tree/236.二叉树的最近公共祖先.java) | 对于树类题目, 状态存储在当前节点的返回值, 递归到每个节点的返回值都是当前节点的值和左子树与右子树的返回 |

## two_pointers

| 题目 | 一句话题解 |
| --- | --- |
| [15.三数之和](resolved/two_pointers/15.三数之和.java) | 排序, 双指针两数和, 记得去重, 去重是和已经记录过成答案的数据比较 , 比如i是和i-1比较, l是和l-1比较 |
