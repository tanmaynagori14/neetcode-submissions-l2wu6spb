class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s = 0, f = 0;

        do {
            s = nums[s];
            f = nums[nums[f]];
        } while (s != f);

        int s2 = 0;
        while (s != s2) {
            s = nums[s];
            s2 = nums[s2];
        }

        return s;
    }
};
