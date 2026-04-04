class Solution {
    vector<vector<int>> dp;

    int fun(int idx, int buy, vector<int>& p) {
        if(idx >= p.size()) return 0;

        if(dp[idx][buy] != -1) return dp[idx][buy];

        int profit;

        if(buy) {
            profit = max(
                -p[idx] + fun(idx+1, 0, p),   // buy
                fun(idx+1, 1, p)              // skip
            );
        } 
        else {
            profit = max(
                p[idx] + fun(idx+2, 1, p),    // sell + cooldown
                fun(idx+1, 0, p)              // hold
            );
        }

        return dp[idx][buy] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.assign(n, vector<int>(2, -1));
        return fun(0, 1, prices);
    }
};