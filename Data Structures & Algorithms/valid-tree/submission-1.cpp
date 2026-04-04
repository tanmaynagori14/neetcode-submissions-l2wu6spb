class Solution {
    vector<vector<int>> adj;
bool isCycle(int node, int parent, vector<int> &vis) {
    vis[node] = true;

    for(auto it : adj[node]) {
        if(it == parent) continue;

        if(vis[it]) return true;

        if(isCycle(it, node, vis)) return true;
    }

    return false;
}
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;
        
        adj.assign(n, vector<int>());
        for(auto it: edges) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);
        for(int i=0 ; i<n ; i++) {
            if(!vis[i]) {
                if(isCycle(i, -1, vis)) return false;
            }
        }

        return true;
    }
};
