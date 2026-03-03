/*
 * @lc app=leetcode.cn id=102 lang=java
 *
 * [102] 二叉树的层序遍历
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
 */

class Solution {
    /**
     * 树的bfs, 注意root可能是null
     */
    public List<List<Integer>> levelOrder(TreeNode root) {
        Deque<TreeNode> que = new ArrayDeque<>();
        if (root != null) que.addLast(root);
        List<List<Integer>> ans = new ArrayList<>();
        while (!que.isEmpty()) {
            List<Integer> arr = new ArrayList<>();
            int cnt = que.size();
            for (int i = 0; i < cnt; i++) {
                TreeNode tmp = que.removeFirst();
                if (tmp.left != null) que.addLast(tmp.left);
                if (tmp.right != null) que.addLast(tmp.right);
                arr.add(tmp.val);
            }
            ans.add(arr);
        }

        return ans;
    }
}
// @lc code=end

