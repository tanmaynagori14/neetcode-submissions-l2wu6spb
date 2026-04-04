class Solution {
    int fun(int r, int c, int m, int n) {
        if(r==m-1 && c==n-1) return 1;

        int down = 0, right = 0;
        if(r+1 < m) down = fun(r+1, c, m, n);
        if(c+1 < n) right = fun(r, c+1, m, n);

        return down + right;
    }
public:
    int uniquePaths(int m, int n) {
        return fun(0, 0, m, n);
    }
};
