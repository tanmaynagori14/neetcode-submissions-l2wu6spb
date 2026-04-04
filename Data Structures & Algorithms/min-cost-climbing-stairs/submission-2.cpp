// class Solution {
//     int fun(int idx, vector<int>& c) {
//         if(idx >= c.size()) {
//             return 0;
//         }

//         int onestep = c[idx] + fun(idx+1,c);
//         int twostep = c[idx] + fun(idx+2,c);

//         return min(onestep, twostep);
//     }
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         return min(fun(0, cost), fun(1, cost));
//     }
// };


// class Solution {
//     int fun(int idx, vector<int>& cost, vector<int>& dp) {
//         if(idx >= cost.size()) {
//             return 0;
//         }

//         if(dp[idx] != -1) {
//             return dp[idx];
//         }

//         int onestep = cost[idx] + fun(idx+1, cost, dp);
//         int twostep = cost[idx] + fun(idx+2, cost, dp);

//         return dp[idx] = min(onestep, twostep);
//     }

// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         vector<int> dp(n, -1);

//         return min(fun(0, cost, dp), fun(1, cost, dp));
//     }
// };


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(n + 2, 0);

        for(int i = n - 1; i >= 0; i--) {
            dp[i] = cost[i] + min(dp[i+1], dp[i+2]);
        }

        return min(dp[0], dp[1]);
    }
};