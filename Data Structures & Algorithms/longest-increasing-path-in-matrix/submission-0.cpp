class Solution {
    int m, n;
    vector<vector<int>> dp;
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,-1,0,1};

    int fun(int r, int c, vector<vector<int>>& arr) {
        if(dp[r][c] != -1) return dp[r][c];

        int ans = 1;
        for(int i=0 ; i<4 ; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr>=0 && nc>=0  && nr<m && nc<n 
            && arr[nr][nc]>arr[r][c]) {
                ans = max(ans, 1 + fun(nr, nc, arr));
            }
        }

        return dp[r][c] = ans;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        m = matrix.size(); n = matrix[0].size();
        dp.assign(m, vector<int>(n, -1));

        for(int i=0 ; i<m ; i++) {
            for(int j=0 ; j<n ; j++) {
                ans =  max(ans, fun(i, j, matrix));
            }
        }

        return ans;
    }
};
