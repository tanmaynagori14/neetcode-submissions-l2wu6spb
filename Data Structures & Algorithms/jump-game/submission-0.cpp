class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndexReach = 0;
        for(int i=0 ; i < nums.size() ; i++) {
            if(maxIndexReach < i) return false;
            maxIndexReach = max(maxIndexReach, i + nums[i]);
        }

        return true;
    }
};
