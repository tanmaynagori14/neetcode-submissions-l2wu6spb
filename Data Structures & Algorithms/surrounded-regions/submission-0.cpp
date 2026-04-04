class Solution {
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,1,0,-1};

    void dfs(int r, int c, vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        board[r][c] = '#';

        for(int i=0;i<4;i++) {

            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m &&
               board[nr][nc] == 'O') {

                dfs(nr,nc,board);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        // check first & last column
        for(int i=0;i<n;i++) {
            if(board[i][0] == 'O') dfs(i,0,board);
            if(board[i][m-1] == 'O') dfs(i,m-1,board);
        }

        // check first & last row
        for(int j=0;j<m;j++) {
            if(board[0][j] == 'O') dfs(0,j,board);
            if(board[n-1][j] == 'O') dfs(n-1,j,board);
        }

        // convert cells
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {

                if(board[i][j] == 'O')
                    board[i][j] = 'X';

                if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};
