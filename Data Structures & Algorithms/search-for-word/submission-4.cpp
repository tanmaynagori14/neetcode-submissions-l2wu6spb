class Solution {
    int m, n;
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,-1,0,1};

    bool fun(int r, int c, int idx, string& word, vector<vector<char>>& b) {
        // if(idx == word.size() - 1) return b[r][c] == word[idx];
        if(b[r][c] != word[idx]) return false;
        if(idx == word.size() - 1) return true;

        char temp = b[r][c];
        b[r][c] = '#'; // mark visited

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nc >= 0 && nr < m && nc < n && b[nr][nc] != '#') {
                if(fun(nr, nc, idx + 1, word, b)) {
                    b[r][c] = temp; // restore before return
                    return true;
                }
            }
        }

        b[r][c] = temp; // backtrack
        return false;
    }
public:
    bool exist(vector<vector<char>>& b, string word) {
        m = b.size(); n = b[0].size();
        for(int i=0 ; i<m ; i++) {
            for(int j=0 ; j<n ; j++) {
                if(fun(i, j, 0, word, b)) return true;
            }
        }

        return false;
    }
};
