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
    private int ans = Integer.MIN_VALUE;

    private int fun(TreeNode root) {
        if(root == null) return 0;

        int left = Math.max(0, fun(root.left));
        int right = Math.max(0, fun(root.right));

        ans = Math.max(ans, root.val + left + right);

        return Math.max(0, root.val + Math.max(left, right));
    }

    public int maxPathSum(TreeNode root) {
        fun(root);
        return ans;
    }
}
