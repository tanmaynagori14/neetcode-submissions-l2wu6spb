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
    int cnt = 0;
    public void fun(TreeNode root, int maxValueYet) {
        if(root == null) return;

        if(root.val >= maxValueYet) cnt++;
        fun(root.left, Math.max(maxValueYet, root.val));
        fun(root.right, Math.max(maxValueYet, root.val));
    }
    public int goodNodes(TreeNode root) {
        fun(root, Integer.MIN_VALUE);
        return cnt;
    }
}

//        3
//      3
//    4   2
