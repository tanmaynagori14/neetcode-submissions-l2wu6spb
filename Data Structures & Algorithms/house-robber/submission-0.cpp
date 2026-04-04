class Solution {
    int fun(int idx, int lastidx, vector<int> &nums, vector<int> &dp) {
        if (idx > lastidx) return 0;

        if (dp[idx] != -1) return dp[idx];

        int nottake = fun(idx + 1, lastidx, nums, dp);
        int take = nums[idx] + fun(idx + 2, lastidx, nums, dp);

        return dp[idx] = max(take, nottake);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return fun(0, n-1, nums, dp);
    }
};
