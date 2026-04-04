class Solution {
    vector<int> dp;

    int fun(int idx, vector<int> &p) {
        if(idx >= p.size()) return 0;

        if(dp[idx] != -1) return dp[idx];

        int profit = fun(idx + 1, p);  // skip today

        for(int i = idx + 1; i < p.size(); i++) {
            profit = max(profit, p[i] - p[idx] + fun(i + 2, p));
        }

        return dp[idx] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.assign(n, -1);
        return fun(0, prices);
    }
};
