class Solution {
    vector<int> dp;
    int fun(int i, int n) {
        if(i == n) return 1;
        if(dp[i] != -1) return dp[i];

        int ans = 0;
        if(i+1 <= n) ans += fun(i+1, n);
        if(i+2 <= n) ans += fun(i+2, n);

        return dp[i] = ans;
    }
public:
    int climbStairs(int n) {
        dp.assign(n+1, -1);
        return fun(0, n);
    }
};
