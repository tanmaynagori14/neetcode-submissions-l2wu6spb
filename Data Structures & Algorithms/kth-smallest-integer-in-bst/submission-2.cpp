// TC: O(k) best case
// SC: O(h)
class Solution {
    int ans;
    void fun(TreeNode* root, int &cnt, int k) {
        if(!root || cnt >= k) return;

        fun(root->left, cnt, k);

        cnt++;
        if(cnt == k) {
            ans = root->val;
            return;
        }

        fun(root->right, cnt, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        fun(root, cnt, k);
        return ans;
    }
};
