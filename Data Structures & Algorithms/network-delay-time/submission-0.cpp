class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it: times) {   
            int u = it[0], v = it[1], w =it[2];
            adj[u].push_back({v, w});
        }

        vector<int> dist(n+1, 1e9);
        dist[k] = 0;

        queue<pair<int, int>> q;
        q.push({k, 0});

        while(!q.empty()) {
            int node = q.front().first;
            int d = q.front().second;
            q.pop();

            for(auto neigh: adj[node]) {
                int newnode = neigh.first;
                int wt = neigh.second;
                if(d + wt < dist[newnode]) {
                    q.push({newnode, d + wt});
                    dist[newnode] = d + wt;
                }
            }
        }

        int mini = INT_MIN;
        for(int i=1 ; i<=n ; i++) {
            mini = max(dist[i], mini);
        }

        if(mini == 1e9) return -1;
        return mini;
        
    }
};
