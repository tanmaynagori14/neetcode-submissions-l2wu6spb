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
    int n;
    unordered_map<int, int> mp;
    TreeNode* fun(int ps, int pe, int is, int ie, vector<int>& preorder, vector<int>& inorder) {
        if(ps > pe) return nullptr;
        if(ps == pe) return new TreeNode(preorder[ps]);


        TreeNode* root = new TreeNode(preorder[ps]);
        int inorderIndex = mp[preorder[ps]];
        int lenLeft = inorderIndex - is;
        int lenRight = ie - inorderIndex;
        
        root->left = fun(ps+1, ps+lenLeft, is, inorderIndex-1, preorder, inorder);
        root->right = fun(ps+lenLeft+1, pe, inorderIndex+1, ie, preorder, inorder);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        n = preorder.size();
        for(int i=0 ; i<n ; i++) {
            mp[inorder[i]] = i;
        }
        return fun(0, n-1, 0, n-1, preorder, inorder);
    }
};
