class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0, r = 0, maxJumps = 0;
        while(r < nums.size()-1) {
            int maxIndexReach = r;
            for (int i = l; i <= min(r, (int)nums.size() - 1); i++) {
                maxIndexReach = max(maxIndexReach, i + nums[i]);
            }
            l = r+1;
            r = maxIndexReach;
            maxJumps++;
        }

        return maxJumps;
    }
};
