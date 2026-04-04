// class Solution {
//     int fun(int idx, int lastidx, vector<int> &nums) {
//         if(idx >= lastidx) return 0;

//         int nottake = fun(idx+1, lastidx, nums);
//         int take = nums[idx] + fun(idx+2, lastidx, nums);

//         return max(take, nottake);
//     }
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         return max(fun(0, n-1, nums), fun(1, n, nums));
//     }
// };

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
        if (n == 1) return nums[0];

        vector<int> dp1(n, -1), dp2(n, -1);

        int case1 = fun(0, n-2, nums, dp1); // exclude last house
        int case2 = fun(1, n-1, nums, dp2);     // exclude first house

        return max(case1, case2);
    }
};


// class Solution {
//     int fun(int startidx, int lastidx, vector<int> &nums, vector<int> dp) {
//         for(int idx = lastidx ; idx>=startidx ; idx--) {
//             int nottake = dp[idx + 1];
//             int take = nums[idx] + dp[idx + 2];

//             dp[idx] = max(take, nottake);
//         }

//         return dp[startidx];
//     }

// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 1) return nums[0];

//         vector<int> dp(n+2, 0);

//         int case1 = fun(0, n-2, nums, dp); // exclude last house
//         int case2 = fun(1, n-1, nums, dp);     // exclude first house

//         return max(case1, case2);
//     }
// };
