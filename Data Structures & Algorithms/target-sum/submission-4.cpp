class Solution {
    int ts = 0;
    vector<vector<int>> dp;
    int fun(int i, int reqdSum, vector<int> &nums) {
        if(i == nums.size()) {
            return reqdSum == 0;
        }

        if(dp[i][reqdSum] != -1) return dp[i][reqdSum];

        int nottake = fun(i+1, reqdSum, nums);
        int take = 0;
        if(reqdSum - nums[i] >=0) {
            take = fun(i+1, reqdSum-nums[i], nums);
        }

        return dp[i][reqdSum] = take + nottake;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        for(auto it: nums) ts += it;
        if((ts-target) % 2 == 1 || ts-target < 0) return 0;

        int reqdSum = (ts + target) / 2;
        dp.assign(nums.size()+1, vector<int>(reqdSum+1, -1));
        return fun(0, reqdSum, nums);
    }
};
