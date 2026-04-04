class Solution {
    int m, n;
    bool isvalid(int r, int c, vector<vector<char>>& b) {
        for(int j = 0; j < 9; j++) {
            if(j == c) continue;
            if(b[r][j] == b[r][c]) return false;
        }

        for(int i = 0; i < 9; i++) {
            if(i == r) continue;
            if(b[i][c] == b[r][c]) return false;
        }

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                int box_row = (r/3)*3 + i;
                int box_col = (c/3)*3 + j;
                if(box_row == r && box_col == c) continue;
                if(b[box_row][box_col] == b[r][c]) return false;
            }
        }

        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        for(int r = 0 ; r < 9 ; r++) {
            for(int c = 0 ; c < 9 ; c++) {
                if(board[r][c] != '.') {
                    if(!isvalid(r, c, board)) return false;
                }
            }
        }

        return true;
    }
};

