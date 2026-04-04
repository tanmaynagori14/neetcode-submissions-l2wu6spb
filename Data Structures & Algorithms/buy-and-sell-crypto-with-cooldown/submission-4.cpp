// class Solution {
//     vector<vector<int>> dp;

//     int fun(int idx, int buy, vector<int>& p) {
//         if(idx >= p.size()) return 0;

//         if(dp[idx][buy] != -1) return dp[idx][buy];

//         int profit;

//         if(buy) {
//             profit = max(
//                 -p[idx] + fun(idx+1, 0, p),   // buy
//                 fun(idx+1, 1, p)              // skip
//             );
//         } 
//         else {
//             profit = max(
//                 p[idx] + fun(idx+2, 1, p),    // sell + cooldown
//                 fun(idx+1, 0, p)              // hold
//             );
//         }

//         return dp[idx][buy] = profit;
//     }

// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         dp.assign(n, vector<int>(2, -1));
//         return fun(0, 1, prices);
//     }
// };


// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();

//         vector<vector<int>> dp(n+2, vector<int>(2, 0));

//         for(int i = n-1; i >= 0; i--) {
//             for(int buy = 0; buy <= 1; buy++) {
//                 if(buy) dp[i][buy] = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
//                 else dp[i][buy] = max(prices[i] + dp[i+2][1], dp[i+1][0]);
//             }
//         }

//         return dp[0][1];
//     }
// };


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // vector<vector<int>> dp(n+2, vector<int>(2, 0));
        vector<int> curr(2, 0), next1(2, 0), next2(2, 0);

        for(int i = n-1; i >= 0; i--) {
            for(int buy = 0; buy <= 1; buy++) {
                if(buy) curr[buy] = max(-prices[i] + next1[0], next1[1]);
                else curr[buy] = max(prices[i] + next2[1], next1[0]);

                next2 = next1;
                next1 = curr;
            }
        }

        return next1[1];
    }
};