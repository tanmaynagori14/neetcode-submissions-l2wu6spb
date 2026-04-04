class Solution {
    vector<vector<int>> dp;
    int n;
    int fun(int idx, int amount , vector<int> &c) {
        if(idx == c.size()) {
            if(amount == 0) return 0;
            return 1e9;
        }

        if(dp[idx][amount] != -1) return dp[idx][amount];

        int nottake = fun(idx + 1, amount, c);
        int take = 1e9;
        if(amount - c[idx] >= 0) {
            take = 1 + min(fun(idx, amount - c[idx], c), fun(idx + 1, amount - c[idx], c));
        }

        return dp[idx][amount] = min(take, nottake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        dp.assign(n+1, vector<int> (amount+1, -1));
        int ans = fun(0, amount, coins);
        if(ans >= 1e9) return -1;
        return ans;
    }
};
