class Solution {
public:
    int search(vector<int>& nums, int k) {
        int s = 0, e = nums.size()-1;
        while(s <= e) {
            int mid = (s + e) >> 1;
            if(nums[mid] == k) return mid;
            else if(nums[s] <= nums[mid]) {
                // left array is sorted
                if(k >= nums[s] && k < nums[mid]) e = mid - 1;
                else s = mid + 1;
            } else {
                // right part is sorted
                if(k > nums[mid] && k <= nums[e]) s = mid + 1;
                else e = mid - 1;
            }
        }

        return -1;
    }
};
