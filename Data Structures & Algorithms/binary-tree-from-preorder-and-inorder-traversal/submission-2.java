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
    // You only need one map to find where root elements sit in the inorder array
    private final Map<Integer, Integer> inMap = new HashMap<>();

    TreeNode fun(int prestart, int preend, int instart, int inend, int[] preorder, int[] inorder) {
        // FIXED: Base case must check if pointers have crossed over
        if (prestart > preend || instart > inend) return null;

        // FIXED: Get the actual node value from preorder array directly
        int rootVal = preorder[prestart];
        TreeNode node = new TreeNode(rootVal);
        
        // FIXED: Get the index of this root value from the inorder map
        int inorderIndex = inMap.get(rootVal);
        int leftLenIninOrder = inorderIndex - instart;

        // Recursively build left and right subtrees
        node.left = fun(prestart + 1, prestart + leftLenIninOrder, instart, inorderIndex - 1, preorder, inorder);
        node.right = fun(prestart + leftLenIninOrder + 1, preend, inorderIndex + 1, inend, preorder, inorder);

        return node;
    }

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        int n = preorder.length;

        // Only map the inorder values to their indices
        for (int i = 0; i < n; i++) {
            inMap.put(inorder[i], i);
        }

        return fun(0, n - 1, 0, n - 1, preorder, inorder);
    }
}
