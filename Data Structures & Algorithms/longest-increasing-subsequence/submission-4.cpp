// class Solution {
//     int n;
//     vector<vector<int>> dp;
//     int fun(int lastidx, int curridx, vector<int> &nums) {
//         if(curridx == n+1) return 0;

//         int nottake = 0 + fun(lastidx, curridx+1, nums);
//         int take = 0;
//         if(lastidx == 0 || nums[curridx-1] > nums[lastidx-1]) {
//             take = 1 + fun(curridx, curridx+1, nums);
//         }

//         return dp[lastidx][curridx] = max(take, nottake);
//     }
    
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         n = nums.size();
//         dp.assign(n+1, vector<int>(n+1, -1));
//         return fun(0, 1, nums);
//     }
// };



class Solution {
    int n;
    vector<vector<int>> dp;
    int fun(int lastidx, int curridx, vector<int> &nums) {
        if(curridx == n+1) return 0;

        int nottake = 0 + fun(lastidx, curridx+1, nums);
        int take = 0;
        if(lastidx == 0 || nums[curridx-1] > nums[lastidx-1]) {
            take = 1 + fun(curridx, curridx+1, nums);
        }

        return dp[lastidx][curridx] = max(take, nottake);
    }
    
public:
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        dp.assign(n+1, vector<int>(n+2, 0));
        for(int lastidx=n ; lastidx>=0 ; lastidx--) {
            for(int curridx=n ; curridx>=1 ; curridx--){
                int nottake = 0 + dp[lastidx][curridx+1];
                int take = 0;
                if(lastidx == 0 || nums[curridx-1] > nums[lastidx-1]) {
                    take = 1 + dp[curridx][curridx+1];
                }

                dp[lastidx][curridx] = max(take, nottake);
            }
        }
        return dp[0][1];
    }
};
