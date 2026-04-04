class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxlen = 0;
        int len = 0;
        for(int i=0 ; i<nums.size() ; i++) {
            if(i==0) {maxlen = 1; len = 1; continue;}
            if(nums[i-1] + 1 == nums[i]) len++;
            else if(nums[i] == nums[i-1]) continue;
            else len = 1;

            maxlen = max(maxlen, len);
        }

        return maxlen;
    }
};
