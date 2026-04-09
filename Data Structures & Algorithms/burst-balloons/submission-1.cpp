// class Solution {
//     int fun(int i, int j, vector<int> &nums) {
//         if(i > j) return 0;

//         int maxcoins = 0;
//         for(int range = i ; range <= j ; range++) {
//             int leftOfRange = i > 0 ? nums[i-1] : 1;
//             int rightOfRange = j <= nums.size()-2 ? nums[j+1] : 1;
//             maxcoins = max(maxcoins, nums[range]*leftOfRange*rightOfRange + fun(i, range-1, nums) + fun(range+1, j, nums));
//         }

//         return maxcoins;
//     }
// public:
//     int maxCoins(vector<int>& nums) {
//         return fun(0, nums.size()-1, nums);
//     }
// };
#include <vector>
#include <cstring>
#include <algorithm>
class Solution {
    int memo[301][301]; // Standard size for LeetCode
    int fun(int i, int j, vector<int> &nums) {
        if(i > j) return 0;
        if(memo[i][j] != -1) return memo[i][j];

        int maxcoins = 0;
        for(int k = i ; k <= j ; k++) {
            // k is the LAST balloon to burst in range [i, j]
            // Therefore, its neighbors are the balloons just outside i and j
            int leftNeighbor = (i > 0) ? nums[i-1] : 1;
            int rightNeighbor = (j < nums.size()-1) ? nums[j+1] : 1;

            int cost = nums[k] * leftNeighbor * rightNeighbor 
                       + fun(i, k-1, nums) 
                       + fun(k+1, j, nums);
            
            maxcoins = max(maxcoins, cost);
        }

        return memo[i][j] = maxcoins;
    }
public:
    int maxCoins(vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        return fun(0, nums.size()-1, nums);
    }
};
