class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       int m = grid.size(), n = grid[0].size();
       queue<pair<int, int>> q;
        for(int i=0 ; i<m ; i++) {
            for(int j=0 ; j<n ; j++) {
                if(grid[i][j] == 2) q.push({i, j});
            }
        } 

        int ans = -1;
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,-1,0,1};
        while(!q.empty()) {
            int sz = q.size();
            while(sz) {
                int r = q.front().first, c = q.front().second;
                q.pop();

                for(int i=0 ; i<4 ; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if( nr>=0 && nc>=0 && nr<m && nc<n
                    && grid[nr][nc] == 1 ) {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                    }
                }
                sz--;
            }
            ans++;
        }
        for(int i=0 ; i<m ; i++) {
            for(int j=0 ; j<n ; j++) {
                if(grid[i][j] == 1) return -1;
            }
        } 

        return ans == -1 ? 0 : ans;
    }
};
