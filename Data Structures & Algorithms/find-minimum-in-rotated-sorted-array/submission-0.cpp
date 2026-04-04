class Solution {
public:
    int findMin(vector<int> &nums) {
        int s = 0, e = nums.size() - 1;
        int ans = INT_MAX;
        while(s <= e) {
            int mid = (s + e) / 2;
            if(nums[s] <= nums[mid]) {
                // we encountered left sorted part
                ans = min(ans, nums[s]);
                s = mid + 1;
            } else {
                // right part is sorted
                ans = min(ans, nums[mid]);
                e = mid - 1;
            }
        }

        return ans;
    }
};
