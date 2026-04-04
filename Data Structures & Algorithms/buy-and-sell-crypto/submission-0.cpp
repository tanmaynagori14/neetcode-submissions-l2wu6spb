class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return -1;
        int mini = INT_MAX;
        int profit = 0;
        for(int i=0; i<prices.size() ; i++) {
            profit = max(profit, prices[i] - mini);
            mini = min(mini, prices[i]);
        }

        return profit;
    }
};
