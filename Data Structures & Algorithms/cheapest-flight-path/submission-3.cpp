// class Solution {
// public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         vector<int> dist(n, 1e9);
//         dist[src] = 0;
//         priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
//         pq.push({0, 0, src}); // {cost, stops, node}
//         int ans = INT_MAX;

//         vector<pair<int, int>> adj[n];
//         for(auto it: flights) {
//             int s = it[0], e = it[1], cost = it[2];
//             adj[s].push_back({e, cost});
//         }

//         while(!pq.empty()) {
//             auto [cost, stops, node] = pq.top();
//             pq.pop();

//             if(node == dst) {
//                 ans = min(ans, cost);
//             }

//             for(auto it: adj[node]) {
//                 int neigh = it.first, d = it.second;
//                 if(cost + d <= dist[neigh] && stops <= k) {
//                     dist[neigh] = cost + d;
//                     pq.push({dist[neigh], stops+1, neigh});
//                 }
//             }
//         }

//         return ans == INT_MAX ? -1 : ans;
//     }
// };



class Solution {
    int ans = INT_MAX;
    vector<vector<pair<int,int>>> adj;

    void dfs(int node, int cost, int dst, int k) {
        if(node == dst) {
            ans = min(ans, cost);
            return;
        }

        if(k == 0) return;

        for(auto &it : adj[node]) {
            int neigh = it.first;
            int d = it.second;

            dfs(neigh, cost + d, dst, k - 1);
        }
    }

public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        adj = vector<vector<pair<int,int>>>(n);

        for(auto &it : flights) {
            int s = it[0], e = it[1], cost = it[2];
            adj[s].push_back({e, cost});
        }

        dfs(src, 0, dst, k + 1);

        return ans == INT_MAX ? -1 : ans;
    }
};