// class Solution {
//     vector<vector<int>> dp;
//     int fun(int r, int c, int m, int n) {
//         if(r==m-1 && c==n-1) return 1;

//         if(dp[r][c] != -1) return dp[r][c];

//         int down = 0, right = 0;
//         if(r+1 < m) down = fun(r+1, c, m, n);
//         if(c+1 < n) right = fun(r, c+1, m, n);

//         return dp[r][c] = down + right;
//     }
// public:
//     int uniquePaths(int m, int n) {
//         dp.assign(m+1, vector<int>(n+1, -1));
//         return fun(0, 0, m, n);
//     }
// };

// class Solution {
//     vector<vector<int>> dp;
//     int fun(int r, int c, int m, int n) {
//         if(r==m-1 && c==n-1) return 1;

//         if(dp[r][c] != -1) return dp[r][c];

//         int down = 0, right = 0;
//         if(r+1 < m) down = fun(r+1, c, m, n);
//         if(c+1 < n) right = fun(r, c+1, m, n);

//         return dp[r][c] = down + right;
//     }
// public:
//     int uniquePaths(int m, int n) {
//         dp.assign(m+1, vector<int>(n+1, 0));
//         dp[m-1][n-1] = 1;

//         for(int r=m-1 ; r>=0 ; r--) {
//             for(int c=n-1 ; c>=0 ; c--) {
//                 if(r==m-1 && c==n-1) continue;
//                 int down = 0, right = 0;
//                 if(r+1 < m) down = dp[r+1][c];
//                 if(c+1 < n) right = dp[r][c+1];

//                 dp[r][c] = down + right;
//             }
//         }
//         return dp[0][0];
//     }
// };



class Solution {
    vector<vector<int>> dp;
    int fun(int r, int c, int m, int n) {
        if(r == m-1 && c == n-1) return 1;
        if(dp[r][c] != -1) return dp[r][c];

        int down = 0, right = 0;
        if(c+1 < n) right = fun(r, c+1, m, n);
        if(r+1 < m) down = fun(r+1, c, m, n);

        return dp[r][c] = right + down;
    }
public:
    int uniquePaths(int m, int n) {
        dp.assign(m, vector<int>(n, 0));

        dp[m-1][n-1] = 1;
        for(int r = m-1 ; r >= 0 ; r--) {
            for(int c = n-1 ; c >= 0 ; c--) {
                if(r == m-1 && c == n-1) continue;

                int down = 0, right = 0;
                if(c+1 < n) right = dp[r][c+1];
                if(r+1 < m) down = dp[r+1][c];

                dp[r][c] = right + down;
            }
        }

        return dp[0][0];
    }
};
