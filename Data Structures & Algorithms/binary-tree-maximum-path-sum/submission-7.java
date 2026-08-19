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
    int ans = Integer.MIN_VALUE;
    private int fun(TreeNode root) {
        if(root == null) return 0;

        int l = Math.max(0, fun(root.left));
        int r = Math.max(0, fun(root.right));

        ans = Math.max(ans, root.val + l + r);

        return Math.max(0, root.val + Math.max(l, r));
    }
    public int maxPathSum(TreeNode root) {
        fun(root);
        return ans;
    }
}
