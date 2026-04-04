class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> suff(n, 1), pref(n, 1);
        for(int i=1 ; i<nums.size() ; i++) {
            pref[i] = pref[i-1] * nums[i-1];
            suff[n-i-1] = suff[n-i-1 + 1] * nums[n-i-1 + 1];
        }

        vector<int> ans(n, 0);
        for(int i=0 ; i<n ; i++) {
            ans[i] = pref[i] * suff[i];
        }

        return ans;
    }
};
