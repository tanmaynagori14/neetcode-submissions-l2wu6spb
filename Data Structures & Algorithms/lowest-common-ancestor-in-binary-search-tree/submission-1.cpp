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

// class Solution {
//     TreeNode* fun(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(root == nullptr || root == p || root == q) return root;

//         TreeNode* l = fun(root->left, p, q);
//         TreeNode* r = fun(root->right, p, q);

//         if(l != nullptr && r != nullptr) return root; // this means this curr node is LCS

//         return l ? l : r;
//     }
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         return fun(root, p, q);
//     }
// };


class Solution {
    TreeNode* fun(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return root;

        if(p->val < root->val && q->val < root->val) {
            return fun(root->left, p, q);
        } else if(p->val > root->val && q->val > root->val) {
            return fun(root->right, p, q);
        } else {
            return root;
        }

        return root;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return fun(root, p, q);
    }
};
