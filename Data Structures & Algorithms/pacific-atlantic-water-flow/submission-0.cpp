class Solution {
    int m, n;
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,-1,0,1};
    
    void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<int>>& heights) {
        vis[r][c] = 1;

        for(int i=0 ; i<4 ; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr>=0 && nc>=0 && nr<m && nc<n
            && !vis[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                dfs(nr, nc, vis, heights);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        
        vector<vector<int>> vis1(m, vector<int>(n, 0)), vis2(m, vector<int>(n, 0));

        for(int i=0 ; i<m ; i++) {
            if(!vis1[i][0]) {
                dfs(i, 0, vis1, heights);
            }
        }       

        for(int j=0 ; j<n ; j++) {
            if(!vis1[0][j]) {
                dfs(0, j, vis1, heights);
            }
        }

        for(int i=0 ; i<m ; i++) {
            if(!vis2[i][n-1]) {
                dfs(i, n-1, vis2, heights);
            }
        } 

        for(int j=0 ; j<n ; j++) {
            if(!vis2[m-1][j]) {
                dfs(m-1, j, vis2, heights);
            }
        } 

        vector<vector<int>> ans;
        for(int i=0 ; i<m ; i++) {
            for(int j=0 ; j<n ; j++) {
                if(vis1[i][j] == 1 && vis2[i][j] == 1) {
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};
