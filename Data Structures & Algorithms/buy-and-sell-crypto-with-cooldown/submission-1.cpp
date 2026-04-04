class Solution {
    int fun(int idx, vector<int> &p) {
        if(idx == p.size()) {
            return 0;
        } 

        int profit = 0;
        for(int i=idx+1 ; i<p.size() ; i++) {
            profit = max(profit, max(p[i] - p[idx] + fun(i+2, p), 0 + fun(idx +1, p)));
        }

        return profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int ans = fun(0, prices);
        return max(ans, 0);
    }
};
