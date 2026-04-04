// class DSU {
// public:
//     vector<int> parent, rank;

//     DSU(int n) {
//         parent.resize(n);
//         rank.resize(n, 0);
//         for(int i = 0; i < n; i++)
//             parent[i] = i;
//     }

//     int findParent(int node) {
//         if(parent[node] == node)
//             return node;
//         return parent[node] = findParent(parent[node]);
//     }

//     bool unionByRank(int u, int v) {
//         int pu = findParent(u);
//         int pv = findParent(v);

//         if(pu == pv) return false;

//         if(rank[pu] < rank[pv]) {
//             parent[pu] = pv;
//         }
//         else if(rank[pv] < rank[pu]) {
//             parent[pv] = pu;
//         }
//         else {
//             parent[pv] = pu;
//             rank[pu]++;
//         }
//         return true;
//     }
// };

// class Solution {
// public:
//     int minCostConnectPoints(vector<vector<int>>& points) {
//         int n = points.size();
//         vector<vector<int>> edges;

//         // Step 1: Build all edges
//         for(int i = 0; i < n; i++) {
//             for(int j = i + 1; j < n; j++) {
//                 int cost = abs(points[i][0] - points[j][0]) +
//                            abs(points[i][1] - points[j][1]);
//                 edges.push_back({cost, i, j});
//             }
//         }

//         // Step 2: Sort edges by weight
//         sort(edges.begin(), edges.end());

//         // Step 3: Apply Kruskal
//         DSU dsu(n);
//         int totalCost = 0;
//         int edgesUsed = 0;

//         for(auto &e : edges) {
//             int cost = e[0];
//             int u = e[1];
//             int v = e[2];

//             if(dsu.unionByRank(u, v)) {
//                 totalCost += cost;
//                 edgesUsed++;
//                 if(edgesUsed == n - 1)
//                     break;
//             }
//         }

//         return totalCost;
//     }
// };


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int N = points.size();
        unordered_map<int, vector<pair<int, int>>> adj;
        for (int i = 0; i < N; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < N; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = abs(x1 - x2) + abs(y1 - y2);
                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});
            }
        }

        int res = 0;
        unordered_set<int> visit;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                                greater<pair<int, int>>> minH;
        minH.push({0, 0});
        while (visit.size() < N) {
            auto curr = minH.top();
            minH.pop();
            int cost = curr.first;
            int i = curr.second;
            if (visit.count(i)) {
                continue;
            }
            res += cost;
            visit.insert(i);
            for (const auto& nei : adj[i]) {
                int neiCost = nei.first;
                int neiIndex = nei.second;
                if (!visit.count(neiIndex)) {
                    minH.push({neiCost, neiIndex});
                }
            }
        }
        return res;
    }
};