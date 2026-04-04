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
    int maxlen = 0;
    int fun(TreeNode* root) {
        if(root == nullptr) return 0;

        int l_len = 0, r_len = 0;
        if(root->left) l_len = 1 + fun(root->left);
        if(root->right) r_len = 1 + fun(root->right);

        maxlen = max(maxlen, l_len + r_len);

        return max(l_len, r_len);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        fun(root);
        return maxlen;
    }
};
