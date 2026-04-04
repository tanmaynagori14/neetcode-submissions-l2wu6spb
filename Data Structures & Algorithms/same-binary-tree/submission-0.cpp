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
    bool fun(TreeNode* p, TreeNode* q) {
        if((!p && q) || (p && !q)) return false;
        if(!p && !q) return true;

        if(p->val == q->val) return fun(p->left, q->left) && fun(p->right, q->right);
        else return false;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return fun(p, q);
    }
};
