class Solution {
    vector<vector<int>> ans;
    int n;

    void fun(int idx, int target, vector<int> &temp, vector<int> &nums) {
        if(idx == n) {
            if(target == 0) {
                ans.push_back(temp);
            }
            return;
        }

        fun(idx+1, target, temp, nums);

        if(target - nums[idx] >= 0) {
            temp.push_back(nums[idx]);
            fun(idx, target-nums[idx], temp, nums);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        n = nums.size();
        fun(0, target, temp, nums);
        return ans;
    }
};
