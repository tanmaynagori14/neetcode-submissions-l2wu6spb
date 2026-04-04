class Solution {
    vector<vector<int>> ans;
    void fun(int idx, vector<int>& nums) {
        if(idx == nums.size()) {
            ans.push_back(nums);
        }

        for(int i=idx ; i<nums.size() ; i++) {
            swap(nums[idx], nums[i]);
            fun(idx+1, nums);
            swap(nums[idx], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        fun(0, nums);
        return ans;
    }
};
