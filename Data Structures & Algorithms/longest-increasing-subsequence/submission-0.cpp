class Solution {
    int fun(int lastidx, int curridx, vector<int> &nums) {
        if(curridx == nums.size()) return 0;

        int nottake = 0 + fun(lastidx, curridx+1, nums);
        int take = 0;
        if(lastidx == -1 || nums[curridx] > nums[lastidx]) {
            take = 1 + fun(curridx, curridx+1, nums);
        }

        return max(take, nottake);
    }
    
public:
    int lengthOfLIS(vector<int>& nums) {
        return fun(-1, 0, nums);
    }
};
