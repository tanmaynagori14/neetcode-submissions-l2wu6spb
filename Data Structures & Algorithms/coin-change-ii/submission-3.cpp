// class Solution {
//     int n;

//     int fun(int i, int a, vector<int> &c, vector<vector<int>> &dp) {
//         if(i == n) {
//             if(a == 0) return dp[i][a] = 1;
//             return dp[i][a] = 0;
//         }

//         if(dp[i][a] != -1) return dp[i][a];

//         int nt = fun(i + 1, a, c, dp);

//         int t = 0;
//         if(a >= c[i]) {
//             t = fun(i, a - c[i], c, dp);
//         }

//         return dp[i][a] = t + nt;
//     }

// public:
//     int change(int amount, vector<int>& c) {
//         n = c.size();
//         vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
//         return fun(0, amount, c, dp);
//     }
// };


class Solution {
public:
    int change(int amount, vector<int>& c) {
        int n = c.size();
        // vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        vector<int> next(amount+1, 0), curr(amount+1, 0);
        next[0] = 1;

        for(int i=n-1 ; i>=0 ; i--) {
            for(int a = 0; a <= amount; a++) {
                int nt = next[a];

                int t = 0;
                if(a >= c[i]) {
                    t = curr[a - c[i]];
                }

                curr[a] = t + nt;
                next[a] = curr[a];
            }
        }

        return next[amount];
    }
};
