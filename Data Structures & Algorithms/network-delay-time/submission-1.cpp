// class Solution {
// public:
//     int networkDelayTime(vector<vector<int>>& times, int n, int k) {
//         vector<vector<pair<int,int>>> adj(n+1);
//         for(auto it: times) {   
//             int u = it[0], v = it[1], w =it[2];
//             adj[u].push_back({v, w});
//         }

//         vector<int> dist(n+1, 1e9);
//         dist[k] = 0;

//         queue<pair<int, int>> q;
//         q.push({k, 0});

//         while(!q.empty()) {
//             int node = q.front().first;
//             int d = q.front().second;
//             q.pop();

//             for(auto neigh: adj[node]) {
//                 int newnode = neigh.first;
//                 int wt = neigh.second;
//                 if(d + wt < dist[newnode]) {
//                     q.push({newnode, d + wt});
//                     dist[newnode] = d + wt;
//                 }
//             }
//         }

//         int mini = INT_MIN;
//         for(int i=1 ; i<=n ; i++) {
//             mini = max(dist[i], mini);
//         }

//         if(mini == 1e9) return -1;
//         return mini;
        
//     }
// };



class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        // Build adjacency list
        vector<vector<pair<int,int>>> adj(n + 1);
        for (auto &t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }

        // Min-heap {distance, node}
        priority_queue<
            pair<int,int>, 
            vector<pair<int,int>>, 
            greater<pair<int,int>>
        > pq;

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        pq.push({0, k});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            // 🔥 Important Optimization
            if (d > dist[node]) continue;

            for (auto &[adjNode, wt] : adj[node]) {
                if (dist[node] + wt < dist[adjNode]) {
                    dist[adjNode] = dist[node] + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};