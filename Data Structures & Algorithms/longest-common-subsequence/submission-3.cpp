class Solution {
    vector<vector<int>> dp;
    int fun(int i, int j, string &p, string &q) {
        if(i == p.length() || j == q.length()) return dp[i][j] = 0;
        if(dp[i][j] != -1) return dp[i][j];

        int res = 0 + fun(i+1, j, p, q);
        res = max(res, 0 + fun(i, j+1, p, q));
        if(p[i] == q[j]) {
            res = max(res, 1 + fun(i+1, j+1, p, q));
        }

        return dp[i][j] = res;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        dp.assign(m+1, vector<int>(n+1, -1));
        return fun(0, 0, text1, text2);
    }
};
