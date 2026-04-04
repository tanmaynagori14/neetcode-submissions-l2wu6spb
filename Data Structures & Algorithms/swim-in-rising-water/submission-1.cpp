// class Solution {
//     int m, n;
//     int ans = INT_MAX;
//     int dr[4] = {-1,0,1,0};
//     int dc[4] = {0,-1,0,1};
//     vector<vector<int>> vis;
//     void dfs(int r, int c, int maxyet, vector<vector<int>> &grid) {
//         if(r == m-1  && c == n-1) {
//             ans = min(ans, maxyet);
//             return;
//         }  

//         vis[r][c] = 1;

//         for(int i=0 ; i<4 ; i++) {
//             int nr = r + dr[i];
//             int nc = c + dc[i];
//             if(nr>=0 && nc>=0 && nr<m && nc<n
//                 && !vis[nr][nc]) {
//                     dfs(nr, nc, max(maxyet, grid[nr][nc]), grid);
//             }
//         }

//         vis[r][c] = 0;
//     }
// public:
//     int swimInWater(vector<vector<int>>& grid) {
//         m = grid.size(), n = grid[0].size();
//         vis.assign(m, vector<int> (n, 0));
//         dfs(0, 0, grid[0][0], grid);
//         return ans;
//     }
// };




class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        vector<vector<int>> vis(n, vector<int>(n,0));

        pq.push({grid[0][0],0,0});

        int dr[4]={-1,0,1,0};
        int dc[4]={0,-1,0,1};

        while(!pq.empty()) {
            auto [t,r,c] = pq.top();
            pq.pop();

            if(vis[r][c]) continue;
            vis[r][c] = 1;

            if(r==n-1 && c==n-1) return t;

            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr>=0 && nc>=0 && nr<n && nc<n && !vis[nr][nc]){
                    pq.push({max(t,grid[nr][nc]),nr,nc});
                }
            }
        }

        return -1;
    }
};