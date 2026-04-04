class Solution {
    vector<vector<int>> ans;

    void fun(int idx, vector<int>& temp, vector<int>& nums) {
        ans.push_back(temp);

        for (int i = idx; i < nums.size(); i++) {
            // Skip duplicates
            if (i > idx && nums[i] == nums[i - 1]) continue;

            temp.push_back(nums[i]);
            fun(i + 1, temp, nums);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        fun(0, temp, nums);
        return ans;
    }
};