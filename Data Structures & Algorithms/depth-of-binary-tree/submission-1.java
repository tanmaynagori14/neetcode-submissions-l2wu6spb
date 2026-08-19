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
    int ans = 0;

    int fun(TreeNode root) {
        if(root == null) return 0;

        int l = 1 + fun(root.left);
        int r = 1 + fun(root.right);

        ans = Math.max(ans, Math.max(l, r));
        return Math.max(l, r);
    }

    public int maxDepth(TreeNode root) {
        return fun(root);
    }
}
