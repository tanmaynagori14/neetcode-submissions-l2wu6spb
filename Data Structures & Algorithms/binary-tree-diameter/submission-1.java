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
    private int ans = 0;
    private int fun(TreeNode root) {
        if(root == null) return 0;

        int l = 0, r = 0;
        if(root.left != null) l = 1 + fun(root.left);
        if(root.right != null) r = 1 + fun(root.right);

        ans = Math.max(ans, l + r);

        return Math.max(l, r);
    }
    public int diameterOfBinaryTree(TreeNode root) {
        fun(root);
        return ans;
    }
}
