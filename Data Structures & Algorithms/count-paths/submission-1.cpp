class Solution {
    vector<vector<int>> dp;
    int fun(int r, int c, int m, int n) {
        if(r==m-1 && c==n-1) return 1;

        if(dp[r][c] != -1) return dp[r][c];

        int down = 0, right = 0;
        if(r+1 < m) down = fun(r+1, c, m, n);
        if(c+1 < n) right = fun(r, c+1, m, n);

        return dp[r][c] = down + right;
    }
public:
    int uniquePaths(int m, int n) {
        dp.assign(m+1, vector<int>(n+1, -1));
        return fun(0, 0, m, n);
    }
};
