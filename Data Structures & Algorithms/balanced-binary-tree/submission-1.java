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
    private boolean ans = true;

    private int fun(TreeNode root) {
        if(root == null) return 0;
        
        int lefth = 1 + fun(root.left);
        int righth = 1 + fun(root.right);

        if(Math.abs(lefth-righth) > 1) ans = false;
        return Math.max(lefth, righth);
    }

    public boolean isBalanced(TreeNode root) {
        fun(root);
        return ans;
    }
}
