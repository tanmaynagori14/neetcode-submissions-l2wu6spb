/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    int maxsum = INT_MIN;
    int fun(TreeNode* root) {
        if(root == nullptr) return 0;

        int val = root->val;
        int leftval = max(0, fun(root->left));
        int rightval = max(0, fun(root->right));

        maxsum = max(maxsum, val + leftval + rightval);

        return max(0, val + max(leftval, rightval));
    }
public:
    int maxPathSum(TreeNode* root) {
        fun(root);
        return maxsum;
    }
};
