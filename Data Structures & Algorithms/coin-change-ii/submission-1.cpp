class Solution {
    int n;

    int fun(int i, int a, vector<int> &c, vector<vector<int>> &dp) {
        if(i == n) {
            if(a == 0) return dp[i][a] = 1;
            return dp[i][a] = 0;
        }

        if(dp[i][a] != -1) return dp[i][a];

        int nt = fun(i + 1, a, c, dp);

        int t = 0;
        if(a >= c[i]) {
            t = fun(i, a - c[i], c, dp);
        }

        return dp[i][a] = t + nt;
    }

public:
    int change(int amount, vector<int>& c) {
        n = c.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        return fun(0, amount, c, dp);
    }
};
