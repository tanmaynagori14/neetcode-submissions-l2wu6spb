class Solution {
    vector<int> row, col, leftdia, rightdia;
    vector<vector<string>> ans;
    vector<string> board;

    bool isValid(int r, int c, int n) {
        if(row[r]) return false;
        if(col[c]) return false;
        if(leftdia[r + c]) return false;
        if(rightdia[r - c + n]) return false;
        return true;
    }

    void solve(int r, int n) {
        if(r == n) {
            ans.push_back(board);
            return;
        }

        for(int c = 0; c < n; c++) {
            if(isValid(r, c, n)) {
                // place queen
                board[r][c] = 'Q';
                row[r] = 1;
                col[c] = 1;
                leftdia[r + c] = 1;
                rightdia[r - c + n] = 1;

                solve(r + 1, n);

                // backtrack
                board[r][c] = '.';
                row[r] = 0;
                col[c] = 0;
                leftdia[r + c] = 0;
                rightdia[r - c + n] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        row.assign(n, 0);
        col.assign(n, 0);
        leftdia.assign(2 * n, 0);
        rightdia.assign(2 * n, 0);

        board.assign(n, string(n, '.'));

        solve(0, n);
        return ans;
    }
};
