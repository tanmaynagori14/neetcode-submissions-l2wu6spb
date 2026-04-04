class DSU {
private:
    vector<int> par, size;
public:
    DSU (int n) {
        par.assign(n+1, 0); size.assign(n+1, 1);
        for(int i=0 ; i<=n ; i++) {
            par[i] = i;
        }
    }

    int findupar(int node) {
        if(par[node] == node) return node;
        return par[node] = findupar(par[node]);
    }

    bool unionBysize(int a, int b) {
        int upa = findupar(a);
        int upb = findupar(b);

        if(upa == upb) return false;

        if(size[upa] > size[upb]) {
            size[upa] += size[upb];
            par[upb] = upa;
        } else {
            size[upb] += size[upa];
            par[upa] = upb;
        }

        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);
        vector<int> ans;

        for(auto it: edges) {
            int u = it[0], v = it[1];
            if(!dsu.unionBysize(u,v)) {
                ans.push_back(u);
                ans.push_back(v);
                break;
            }
        }

        return ans;
    }
};
