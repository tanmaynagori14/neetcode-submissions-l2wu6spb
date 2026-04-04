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
    bool ans = true;
    int fun(TreeNode* root) {
        if(root == nullptr) return 0;
        
        int lefth = 1 + fun(root->left);
        int righth = 1 + fun(root->right);

        if(abs(lefth-righth) > 1) ans = false;
        return max(lefth, righth);
    }
public:
    bool isBalanced(TreeNode* root) {
        fun(root);
        return ans;
    }
};
