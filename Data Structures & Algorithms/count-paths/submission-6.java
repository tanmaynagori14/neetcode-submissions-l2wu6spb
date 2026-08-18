class Solution {
    int m, n;

    int fun(int r, int c) {
        if(r == m-1 && c == n-1) return 1;

        int down = 0, right = 0;
        if(r < m-1) down = fun(r+1, c);
        if(c < n-1) right = fun(r, c+1);

        return down + right;
    }

    public int uniquePaths(int p, int q) {
        m = p; n = q;
        // return fun(0, 0);

        int[][] dp = new int[p][q];
        dp[m-1][n-1] = 1;

        for(int r=m-1 ; r>=0 ; r--) {
            for(int c=n-1 ; c>=0 ; c--) {
                if(r==m-1 && c==n-1) continue;

                int down = 0, right = 0;
                if(r < m-1) down = dp[r+1][c];
                if(c < n-1) right = dp[r][c+1];

                dp[r][c] = down + right;
            }
        }

        return dp[0][0];
    }
}
