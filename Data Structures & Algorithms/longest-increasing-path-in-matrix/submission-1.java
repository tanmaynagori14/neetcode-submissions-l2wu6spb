class Solution {

    // Directions: Up, Right, Down, Left
    private final int[] dr = {-1, 0, 1, 0};
    private final int[] dc = {0, 1, 0, -1};

    private int m, n;
    private int[][] dp;

    /**
     * Returns the length of the longest increasing path
     * starting from cell (r, c).
     */
    private int dfs(int r, int c, int[][] matrix) {

        // If already computed, return the stored answer.
        if (dp[r][c] != 0) {
            return dp[r][c];
        }

        // Every cell itself forms a path of length 1.
        dp[r][c] = 1;

        // Explore all four directions.
        for (int i = 0; i < 4; i++) {

            int nr = r + dr[i];
            int nc = c + dc[i];

            // Check boundaries and ensure the next value is greater.
            if (nr >= 0 && nr < m &&
                nc >= 0 && nc < n &&
                matrix[nr][nc] > matrix[r][c]) {

                dp[r][c] = Math.max(
                        dp[r][c],
                        1 + dfs(nr, nc, matrix)
                );
            }
        }

        return dp[r][c];
    }

    public int longestIncreasingPath(int[][] matrix) {

        if (matrix == null || matrix.length == 0) {
            return 0;
        }

        m = matrix.length;
        n = matrix[0].length;

        // Memoization table.
        dp = new int[m][n];

        int ans = 0;

        // Compute the longest path starting from every cell.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = Math.max(ans, dfs(i, j, matrix));
            }
        }

        return ans;
    }
}