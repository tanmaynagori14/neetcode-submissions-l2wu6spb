class Solution {
    int m, n;
    vector<vector<int>> dp;
    int fun(int i, int j, string& w1, string& w2) {
        if(i == m || j == n) {
            if(i == m && j == n) return dp[i][j] = 0;
            if(i != m) return dp[i][j] = m - i;
            if(j != n) return dp[i][j] = n - j;
            return dp[i][j] = 1e9;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(w1[i] == w2[j]) return dp[i][j] = 0 + fun(i+1, j+1, w1, w2);
        int insertOp = 1 + fun(i, j+1, w1, w2);
        int deleteOp = 1 + fun(i+1, j, w1, w2);
        int replaceOp = 1 + fun(i+1, j+1, w1, w2);

        return dp[i][j] = min(insertOp, min(deleteOp, replaceOp));
    }
public:
    int minDistance(string word1, string word2) {
        m = word1.length(); n = word2.length();
        dp.assign(m+1, vector<int>(n+1, -1));
        return fun(0, 0, word1, word2);
    }
};
