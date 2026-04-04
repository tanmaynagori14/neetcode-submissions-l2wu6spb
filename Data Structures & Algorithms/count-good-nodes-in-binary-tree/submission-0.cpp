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
    int fun(int maxyet, TreeNode* root) {
        if(!root) return 0;


        if(root->val >= maxyet) {
            return 1 + fun(root->val, root->left) + fun(root->val, root->right);
        } else {
            return 0 + fun(maxyet, root->left) + fun(maxyet, root->right);
        }
    }
public:
    int goodNodes(TreeNode* root) {
        return fun(INT_MIN, root);
    }
};
