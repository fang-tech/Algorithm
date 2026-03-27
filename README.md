# Algorithm Solutions

## 题目统计

| 分类 | 数量 | 占比 |
| --- | --- | --- |
| **array** | 13 | 15.48% |
| **bfs** | 2 | 2.38% |
| **binary_search** | 3 | 3.57% |
| **dfs** | 7 | 8.33% |
| **dp** | 17 | 20.24% |
| **graph** | 1 | 1.19% |
| **linkedlist** | 14 | 16.67% |
| **math** | 1 | 1.19% |
| **sliding_window** | 4 | 4.76% |
| **stack** | 1 | 1.19% |
| **string** | 10 | 11.90% |
| **structure** | 4 | 4.76% |
| **tree** | 4 | 4.76% |
| **two_pointers** | 3 | 3.57% |


## array

| 题目 | 一句话题解 |
| --- | --- |
| [121.买卖股票的最佳时机](resolved/array/121.买卖股票的最佳时机.java) | 枚举卖出的价格, 维护最小的买入价格 |
| [1262.可被三整除的最大和](resolved/array/1262.可被三整除的最大和.java) | DP: dfs(i, j): 前i个数字中, 选出来的集合余数为j, 返回集合的最大和 nums[i] % 3 == x; 不选这个元素, dfs(i, j) = dfs(i-1, j), 选择这个元素, dfs(i, j) = dfs(i-1, (j-x) mod 3) |
| [16.最接近的三数之和](resolved/array/16.最接近的三数之和.java) | 三数之和, 每次都更新答案版 |
| [215.数组中的第k个最大元素](resolved/array/215.数组中的第k个最大元素.java) |  |
| [2946.循环移位后的矩阵相似检查](resolved/array/2946.循环移位后的矩阵相似检查.java) |  |
| [31.下一个排列](resolved/array/31.下一个排列.java) | 当找到数字nums[i] < nums[i+1]的时候, 说明存在更大数字, 向前找到第一个 > nums[i]的数字, 将这两个数字交换, 然后在反转剩下的部分, 就是能得到的最小的下一个排列 |
| [41.缺失的第一个正数](resolved/array/41.缺失的第一个正数.java) | 交换当前元素, 直到当前元素不是范围内元素或者成功替换了, edge case是重复元素, 会导致无限循环 |
| [54.螺旋矩阵](resolved/array/54.螺旋矩阵.java) | 发现横向和纵向在各自的方向上, 每轮走的步数--, 需要注意起点在(0, -1) |
| [56.合并区间](resolved/array/56.合并区间.java) | 按照第一个数字升序排序, 然后合 |
| [560.和为-k-的子数组](resolved/array/560.和为-k-的子数组.java) | **前缀和 + 枚举**</br> 计算[left, right]子数组和==k的问题能转化成s[right] -s[left] == k的前缀和问题 即计算s[right] - s[left] == k的数量, 这就变成了一个两数之和的问题了. hashmap: key -> right前面的前缀和值 value -> 出现的次数, 要注意等于key==0的边界情况 |
| [704.二分查找](resolved/array/704.二分查找.java) |  |
| [88.合并两个有序数组](resolved/array/88.合并两个有序数组.java) | 从后往前排, 和合并链表一样的思路, 不过这里nums1剩下的时候可以不用再合并了 |
| [912.排序数组](resolved/array/912.排序数组.java) |  |

## bfs

| 题目 | 一句话题解 |
| --- | --- |
| [102.二叉树的层序遍历](resolved/bfs/102.二叉树的层序遍历.java) | 树的bfs, 注意root可能是null |
| [103.二叉树的锯齿形层序遍历](resolved/bfs/103.二叉树的锯齿形层序遍历.java) | 最简单的思路就是简单的层序遍历 + Collections反转 也可以分成left2righ和right2left两种情况讨论, 让每次切换遍历方向的时候, 也更换push和pop的对应的方向, 还有先left还是先right |

## binary_search

| 题目 | 一句话题解 |
| --- | --- |
| [34.在排序数组中查找元素的第一个和最后一个位置](resolved/binary_search/34.在排序数组中查找元素的第一个和最后一个位置.java) | 二分搜索, 分别找到第一个 >= target的元素, 和 >= target + 1的元素, 边界条件: 这个元素不存在于数组中, 或者所有的元素都 < target, 导致lower_bound返回nums.length @param nums @param target @return |
| [4.寻找两个正序数组的中位数](resolved/binary_search/4.寻找两个正序数组的中位数.java) | 需要重温 |
| [69.x-的平方根](resolved/binary_search/69.x-的平方根.java) | 二分查找, 注意不能计算mid^2会导致越界, left在开区间的情况下应该从0开始 |

## dfs

| 题目 | 一句话题解 |
| --- | --- |
| [200.岛屿数量](resolved/dfs/200.岛屿数量.java) | dfs只用来标记是不是已经访问过了, 遍历所有的节点, 不要使用MAP, 所有的返回条件都放在递归结束的位置做 |
| [22.括号生成](resolved/dfs/22.括号生成.java) | 选左括号还是右括号, 只有右括号的剩余数量大于左括号的剩余数量才能选 |
| [39.组合总和](resolved/dfs/39.组合总和.java) | 选或不选的经典题目 |
| [40.组合总和-ii](resolved/dfs/40.组合总和-ii.java) | 排序 + 选或不选, 这里比较subtle的是重复问题, 假如x = can[i], x' = can[i+1], 选x不选x' 不选x'选x 这样就会导致重复, 为了避免重复, 我们如果不选, 就要跳过所有和当前can相等的can |
| [46.全排列](resolved/dfs/46.全排列.java) | 每个槽位可以选什么数字, dfs, 记录哪个数字用过了 |
| [695.岛屿的最大面积](resolved/dfs/695.岛屿的最大面积.java) | dfs遍历, dfs返回值是以当前坐标为起点的连通陆地面积 |
| [79.单词搜索](resolved/dfs/79.单词搜索.java) | 岛屿搜索 |

## dp

| 题目 | 一句话题解 |
| --- | --- |
| [1143.最长公共子序列](resolved/dp/1143.最长公共子序列.java) | dfs(i, j): word1前i个字符和word2前j个字符之间的最长子序列长度 @param text1 @param text2 @return |
| [122.买卖股票的最佳时机-ii](resolved/dp/122.买卖股票的最佳时机-ii.java) | dfs(i, hold) return int 如果要持有股票, 则最大利润为max(dfs(i-1, 1), dfs(i-1, 0) - prices[i]) 如果要不持有股票, 则最大利润为max(dfs(i-1, 0), dfs(i-1, 0) + prices[i]) |
| [152.乘积最大子数组](resolved/dp/152.乘积最大子数组.java) | 最大子数组和的乘法版本, dp, 计算以nums[i]结尾的最大子数组乘积, 同时记录最大子数组和最小子数组(因为有负数的情况) |
| [198.打家劫舍](resolved/dp/198.打家劫舍.java) | dp, 偷或不偷 f[i+1][0] = max(f[i][1], f[i][0]); f[i+1][1] = max(f[i][1], f[i][0] + nums[i]); @param nums @return |
| [213.打家劫舍-ii](resolved/dp/213.打家劫舍-ii.java) | 选了第一家, 则问题退化成求[2, n-1)范围的最大值, 不选第一家, 则问题退化成求[1, n)范围的最大值 @param nums @return |
| [300.最长递增子序列](resolved/dp/300.最长递增子序列.java) |  |
| [322.零钱兑换(递归)](resolved/dp/322.零钱兑换(递归).java) | DFS 状态定义：dfs(i, j) 表示仅使用前 i 种硬币（下标范围 [0...i]）， 刚好凑出总金额为 j 时，所需要的最少硬币数量。 对于第 i 种硬币，我们可以： 1. 不选它：直接看前 i-1 种硬币，状态转移为 dfs(i-1, j) 2. 选它：因为硬币数量无限，我们还可以继续选第 i 种硬币（下标 i 不变），状态转移为 dfs(i, j - coins[i]) + 1 |
| [322.零钱兑换(递推)](resolved/dp/322.零钱兑换(递推).java) |  |
| [416.分割等和子集](resolved/dp/416.分割等和子集.java) | 背包问题 |
| [516.最长回文子序列](resolved/dp/516.最长回文子序列.java) | 区间dp, 从两侧向中间缩减范围, 子序列问题本质上是选或不选, 如果两侧的字母一致, 说明能都选, 状态 -> dfs(i+1, j-1), 如果两侧的字母不一致, 说明不能都选 |
| [53.最大子数组和](resolved/dp/53.最大子数组和.java) | dp, 以这个数字为结尾的最大子数组和 |
| [64.最小路径和(递归)](resolved/dp/64.最小路径和(递归).java) | dp递归, m[x][y] = min(dfs(x-1, y), dfs(x, y-1)) + grid[x][y]; 注意: 对于dfs(0, 0)需要特殊处理, 返回零, 不然会因为dfs(0, -1)和dfs(-1, 0)都为Integer.MAX_VALUE导致错误 @param grid @return |
| [64.最小路径和(递推)](resolved/dp/64.最小路径和(递推).java) | 递推一比一翻译过来即可, 这里缩减了计算图, 让f[j]的值表示f[i+1][j], f[j+1]表示了f[i][j+1] |
| [70.爬楼梯](resolved/dp/70.爬楼梯.java) | 最简单的DP! |
| [72.编辑距离(递归)](resolved/dp/72.编辑距离(递归).java) | 思路和递推版一致, dfs(i,j): word1前i个字符被转化成word2前j个字符需要的最少步数 递归的返回条件分别是记忆化搜索, i/j越界 |
| [72.编辑距离(递推)](resolved/dp/72.编辑距离(递推).java) | 递推版本: f[i+1][j+1] word1前i+1个字符转化成word2前j+1个字符所需的最小操作数 操作都只对word1操作 插入操作: 插入的字符将j+1给抵消掉了, 所以情况变成了f[i+1][j]+1 删除操作: 删除了一个字符, i+1被删了, f[i][j+1]+1 修改操作: i+1和j+1都被抵消掉了 |
| [97.交错字符串](resolved/dp/97.交错字符串.java) | |n-m| <= 1是伪条件, 选或不选, dp记录返回 |

## graph

| 题目 | 一句话题解 |
| --- | --- |
| [207.课程表](resolved/graph/207.课程表.java) | 题目转化成了, 图中有没有环, 如果有环, 说明就无法上完课, 这里还可以通过记忆化递归, 记忆好某个节点是不是已经确定了不会有环出现了 |

## linkedlist

| 题目 | 一句话题解 |
| --- | --- |
| [141.环形链表](resolved/linkedlist/141.环形链表.java) | 快慢指针, 重合即是有环 |
| [142.环形链表-ii](resolved/linkedlist/142.环形链表-ii.java) | 设slow从head走到环起始点a步, 从head走到相遇点走了b步, 环长c步 设fast比slow多走了k圈, 2b - b = kc => b = kc; slow在环中走了b - a步, 即走了kc - a步, 所以slow再走a步就能到达环起点 |
| [143.重排链表](resolved/linkedlist/143.重排链表.java) | 获取中间节点, 从中间节点开始反转链表 将两个的链表合并, 需要注意的是两个子链表的末尾都是第二个反转后的链表的tail |
| [148.排序链表](resolved/linkedlist/148.排序链表.java) | 链表版本归并排序, 外层sortfindmiddle, 切分链表, 然后partitionMerge合并两个链表 |
| [160.相交链表](resolved/linkedlist/160.相交链表.java) | 假设A自己私有的部分长度是m, B是n, 公用的部分是x, (m < n) 通过A, B同时向前走, A走完的时候, B停在离终点还有n - m步骤, 这个时候再让B head n-m步, 这个时候, 两个链表向前走一起向前走m步就会相遇, 也就是一起向前走就会相遇 |
| [19.删除链表的倒数第-n-个结点](resolved/linkedlist/19.删除链表的倒数第-n-个结点.java) | 两个指针, fast和slow之间相差n个节点, fast到最后一个node的时候, slow在要删除的节点的前一个node, 执行删除 |
| [2.两数相加](resolved/linkedlist/2.两数相加.java) | 按位加即可, 链表版大数和 |
| [206.反转链表](resolved/linkedlist/206.反转链表.java) | 三指针, cur是当前要反转的节点 next在反转前移动 |
| [21.合并两个有序链表](resolved/linkedlist/21.合并两个有序链表.java) |  |
| [234.回文链表](resolved/linkedlist/234.回文链表.java) | 找到中点前一个节点, 然后反转后一部分, 最后比较, 出现不同return false |
| [24.两两交换链表中的节点](resolved/linkedlist/24.两两交换链表中的节点.java) | 反转k个节点的k==2版本 |
| [25.k-个一组翻转链表](resolved/linkedlist/25.k-个一组翻转链表.java) | 翻转每一段链表, 要有dummy, 找到每段链表翻转前的head, head.prev, last, last.next |
| [82.删除排序链表中的重复元素-ii](resolved/linkedlist/82.删除排序链表中的重复元素-ii.java) | 如果cur的下两个节点都存在, 并且两个节点的值都相同, 则开始删除和cur.next值相同的节点, 否则cur向前一步 @param head @return |
| [92.反转链表-ii](resolved/linkedlist/92.反转链表-ii.java) | 创建dummy节点, 记录要反转的区间的前一个节点和下一个节点, 还有反转后的链表的head(prev)和tail(由dummy.next记录) 是按k个反转链表的退阶题目 |

## math

| 题目 | 一句话题解 |
| --- | --- |
| [470.用-rand-7-实现-rand-10](resolved/math/470.用-rand-7-实现-rand-10.java) | The rand7() API is already defined in the parent class SolBase. public int rand7(); @return a random integer in the range 1 to 7 |

## sliding_window

| 题目 | 一句话题解 |
| --- | --- |
| [209.长度最小的子数组](resolved/sliding_window/209.长度最小的子数组.java) | 滑动窗口, 当windowSum >= target的时候记录答案, 然后滑动left到 windowSum < target |
| [239.滑动窗口最大值](resolved/sliding_window/239.滑动窗口最大值.java) | 单调队列, first最大, 队列里面存储的是数组 从Last queue的时候, 如果Last < nums[i] 则rmLast |
| [3.无重复字符的最长子串](resolved/sliding_window/3.无重复字符的最长子串.java) | 使用滑动窗口, 如果某个字符出现的次数大于1, left++, 直到所有字符的出现次数都小等于1, 在这个时刻尝试更新答案 |
| [76.最小覆盖子串](resolved/sliding_window/76.最小覆盖子串.java) |  |

## stack

| 题目 | 一句话题解 |
| --- | --- |
| [20.有效的括号](resolved/stack/20.有效的括号.java) | stack |

## string

| 题目 | 一句话题解 |
| --- | --- |
| [14.最长公共前缀](resolved/string/14.最长公共前缀.java) | 遍历 + 维护公共子串 |
| [151.反转字符串中的单词](resolved/string/151.反转字符串中的单词.java) | 提取word, insert到ans的head |
| [165.比较版本号](resolved/string/165.比较版本号.java) | 从版本号中提取数字, 默认是0, 直到两个字符串都匹配完了, 仍然没有找到更大的, 则返回0(循环外) |
| [179.最大数](resolved/string/179.最大数.java) | 两层遍历, 形似插入排序, 每次找到能最大化添加的数字append到ans里面 |
| [32.最长有效括号](resolved/string/32.最长有效括号.java) | list里面存的是没有匹配的'('的索引, 那么每次匹配的到的时候, 就可以通过(i - 最近的没有匹配到的'('的index), 来计算得到当前的连续括号长度, 初始化的时候stack里面存一个-1来作为哨兵 @param s @return |
| [394.字符串解码](resolved/string/394.字符串解码.java) | 在碰到']'的处理整个模式, 数字的处理, 这里是反序的, 是不是正序读, 要通过位数计算当前数字要乘的10^x, 注意反转 |
| [415.字符串相加](resolved/string/415.字符串相加.java) |  |
| [43.字符串相乘](resolved/string/43.字符串相乘.java) |  |
| [5.最长回文子串](resolved/string/5.最长回文子串.java) | 中心扩散, 分成奇偶回文序列两种情况分别遍历 |
| [93.复原-ip-地址](resolved/string/93.复原-ip-地址.java) | 递归回溯在i位置分割还是不分割, 最后一个节点一定要分割, 有前导0不能不分割 @param s @return |

## structure

| 题目 | 一句话题解 |
| --- | --- |
| [1.两数之和](resolved/structure/1.两数之和.java) | hashmap<num, index> |
| [128.最长连续序列](resolved/structure/128.最长连续序列.java) | 将元素都存储到集合里面, 遍历集合里面的元素, 如果这个元素是序列的起点(num-1不在set中), 则向后找后续的序列 |
| [146.lru-缓存](resolved/structure/146.lru-缓存.java) | hashmap key: key, val: node node : key, value, prev, next; |
| [232.用栈实现队列](resolved/structure/232.用栈实现队列.java) | 维护一个enque队列和deque队列, 在要deque/peek的时候, 如果deque empty, 则把enque中的元素都倒到deque @param x |

## tree

| 题目 | 一句话题解 |
| --- | --- |
| [124.二叉树中的最大路径和](resolved/tree/124.二叉树中的最大路径和.java) | 核心思想：后序遍历（DFS） 1. DFS 函数的作用是计算并返回以当前节点为终点的“单侧最大路径和”（只能继续走左子树或右子树），提供给父节点使用。 2. 在遍历过程中，同时计算以当前节点为“最高点”（可以同时包含左右子树）的“最大局部路径和”，并全局维护更新 ans。 3. 贪心策略：如果某个子树的单侧路径和为负数，把它加到路径里只会让总和变小。这时候我们将其置为 0，代表“不选这颗子树的路径”。 |
| [199.二叉树的右视图](resolved/tree/199.二叉树的右视图.java) | 先递归右子树, 再递归左子树, 记录层高, 第一次到达该层的时候, 记录答案 @param root @return |
| [236.二叉树的最近公共祖先](resolved/tree/236.二叉树的最近公共祖先.java) | 对于树类题目, 状态存储在当前节点的返回值, 递归到每个节点的返回值都是当前节点的值和左子树与右子树的返回 |
| [662.二叉树最大宽度](resolved/tree/662.二叉树最大宽度.java) | 维护两个队列, 一个是node, 一个是这个node在一个完全二叉树中的位置, 每层记录最左边的节点和最右边的节点的位置, 计算ans |

## two_pointers

| 题目 | 一句话题解 |
| --- | --- |
| [15.三数之和](resolved/two_pointers/15.三数之和.java) | 排序, 双指针两数和, 记得去重, 去重是和已经记录过成答案的数据比较 , 比如i是和i-1比较, l是和l-1比较 |
| [283.移动零](resolved/two_pointers/283.移动零.java) | 双指针, 这里比较subtle的写法是, 在碰到非0元素的时候, 发生交换, 并且left才向前移动, 发生交换的时机总是在非0元素上, 并且这个时候right在0区间的后面的第一个元素, left总在0区间的开头, 交换让整个0区间向后移动了一格 |
| [42.接雨水](resolved/two_pointers/42.接雨水.java) | 双指针法：动态维护左侧最高点（前缀最大值）和右侧最高点（后缀最大值）。 某个位置能接的雨水量，由其左右两端最高柱子中的较矮者决定， 即能接的雨水量 = min(最大前缀, 最大后缀) - 当前的高度。 |
