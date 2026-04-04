class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int totalsubsets = pow(2, n)-1;
        vector<vector<int>> ans;
        for(int i=0 ; i<=totalsubsets ; i++) {
            int num = i, j = 0;
            vector<int> temp;
            while(num) {
                if(num & 1) {
                    temp.push_back(nums[j]);
                }
                j++;
                num = num >> 1;
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
