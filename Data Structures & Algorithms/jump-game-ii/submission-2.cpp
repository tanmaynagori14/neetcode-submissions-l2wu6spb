// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         int l = 0, r = 0, maxJumps = 0;
//         while(r < nums.size()-1) {
//             int maxIndexReach = r;
//             for (int i = l; i <= min(r, (int)nums.size() - 1); i++) {
//                 maxIndexReach = max(maxIndexReach, i + nums[i]);
//             }
//             l = r+1;
//             r = maxIndexReach;
//             maxJumps++;
//         }

//         return maxJumps;
//     }
// };


class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0, r = 0, jumps = 0;
        int n = nums.size();

        while (r < n - 1) {
            int maxReach = r;

            for (int i = l; i <= r; i++) {
                maxReach = max(maxReach, i + nums[i]);
            }

            l = r + 1;
            r = maxReach;
            jumps++;
        }

        return jumps;
    }
};