// class Solution {
// public:
//     int findMin(vector<int> &nums) {
//         int s = 0, e = nums.size() - 1;
//         int ans = INT_MAX;
//         while(s <= e) {
//             int mid = (s + e) / 2;
//             if(nums[s] <= nums[mid]) {
//                 // we encountered left sorted part
//                 ans = min(ans, nums[s]);
//                 s = mid + 1;
//             } else {
//                 // right part is sorted
//                 ans = min(ans, nums[mid]);
//                 e = mid - 1;
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0, e = nums.size() - 1;

        while(s < e) {
            int mid = s + (e - s) / 2;

            // if mid element is greater than rightmost
            // minimum lies in right half
            if(nums[mid] > nums[e]) {
                s = mid + 1;
            } else {
                // minimum lies in left half (including mid)
                e = mid;
            }
        }

        return nums[s];
    }
};
