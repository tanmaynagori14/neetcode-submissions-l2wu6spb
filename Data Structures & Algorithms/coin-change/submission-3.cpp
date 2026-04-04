// class Solution {
//     vector<vector<int>> dp;
//     int n;
//     int fun(int idx, int amount , vector<int> &c) {
//         if(idx == c.size()) {
//             if(amount == 0) return 0;
//             return 1e9;
//         }

//         if(dp[idx][amount] != -1) return dp[idx][amount];

//         int nottake = fun(idx + 1, amount, c);
//         int take = 1e9;
//         if(amount - c[idx] >= 0) {
//             take = 1 + min(fun(idx, amount - c[idx], c), fun(idx + 1, amount - c[idx], c));
//         }

//         return dp[idx][amount] = min(take, nottake);
//     }
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         n = coins.size();
//         dp.assign(n+1, vector<int> (amount+1, -1));
//         int ans = fun(0, amount, coins);
//         if(ans >= 1e9) return -1;
//         return ans;
//     }
// };


// class Solution {
// public:
//     int coinChange(vector<int>& c, int amt) {
//         int n = c.size();

//         vector<vector<int>> dp (n+1, vector<int> (amt+1, 1e9));
//         dp[n][0] = 0;

//         for(int idx = n-1 ; idx>=0 ; idx--) {
//             for(int amount = 0 ; amount <= amt ; amount++) {
//                 int nottake = dp[idx + 1][amount];
//                 int take = 1e9;
//                 if(amount - c[idx] >= 0) {
//                     take = 1 + min(dp[idx][amount - c[idx]], dp[idx + 1][amount - c[idx]]);
//                 }

//                 dp[idx][amount] = min(take, nottake);
//             }
//         }

//         int ans = dp[0][amt];
//         if(ans >= 1e9) return -1;
//         return ans;
//     }
// };



class Solution {
public:
    int coinChange(vector<int>& c, int amt) {
        int n = c.size();

        vector<int> next(amt+1, 1e9);
        vector<int> curr(amt+1, 1e9);
        next[0] = 0;

        for(int idx = n-1 ; idx>=0 ; idx--) {
            for(int amount = 0 ; amount <= amt ; amount++) {
                int nottake = next[amount];
                int take = 1e9;
                if(amount - c[idx] >= 0) {
                    take = 1 + min(curr[amount - c[idx]], next[amount - c[idx]]);
                }

                curr[amount] = min(take, nottake);
                next[amount] = curr[amount];
            }
        }

        int ans = next[amt];
        if(ans >= 1e9) return -1;
        return ans;
    }
};