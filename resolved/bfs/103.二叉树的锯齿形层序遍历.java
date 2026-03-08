package resolved.bfs;
/*
 * @lc app=leetcode.cn id=103 lang=java
 *
 * [103] 二叉树的锯齿形层序遍历
 */

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    /**
     * 最简单的思路就是简单的层序遍历 + Collections反转
     * 也可以分成left2righ和right2left两种情况讨论,
     * 让每次切换遍历方向的时候, 也更换push和pop的对应的方向,
     * 还有先left还是先right
     */
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        if (root == null) return List.of();
        List<List<Integer>> ans = new ArrayList<>();
        boolean left2right = true;
        Deque<TreeNode> st = new ArrayDeque<>();
        st.addLast(root);
        while (!st.isEmpty()) {
            int size = st.size();
            List<Integer> curLevel = new ArrayList<>();
            for (int i = 0; i < size; i++) {
                TreeNode cur = left2right ? st.removeFirst() : st.removeLast();
                curLevel.add(cur.val);
                if (left2right) {
                    if (cur.left != null) st.addLast(cur.left);
                    if (cur.right != null) st.addLast(cur.right);
                } else {
                    if (cur.right != null) st.addFirst(cur.right);
                    if (cur.left != null) st.addFirst(cur.left);
                }
            }
            ans.add(curLevel);
            left2right = !left2right;
        }
        return ans;
    }
}
// @lc code=end

