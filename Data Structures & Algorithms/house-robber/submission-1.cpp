// class Solution {
//     int fun(int idx, int lastidx, vector<int> &nums, vector<int> &dp) {
//         if (idx > lastidx) return 0;

//         if (dp[idx] != -1) return dp[idx];

//         int nottake = fun(idx + 1, lastidx, nums, dp);
//         int take = nums[idx] + fun(idx + 2, lastidx, nums, dp);

//         return dp[idx] = max(take, nottake);
//     }
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n, -1);
//         return fun(0, n-1, nums, dp);
//     }
// };

class Solution {
    int fun(int startidx, int lastidx, vector<int> &nums, vector<int> dp) {
        int curr=0, next1=0, next2=0;
        for(int idx = lastidx ; idx>=startidx ; idx--) {
            curr = max(next1, nums[idx] + next2);
            next2 = next1;
            next1 = curr;
        }

        return next1;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return fun(0, n-1, nums, dp);
    }
};
