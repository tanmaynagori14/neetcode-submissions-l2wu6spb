class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        unordered_map<int, vector<int>> adj;
        unordered_set<int> totalDiffchars;

        for(auto it: words) {
            for(auto s: it) {
                totalDiffchars.insert(s-'a');
            }
        }

        for(int k=1 ; k<n ; k++) {
            string w1 = words[k-1];
            string w2 = words[k];
            int i=0, j=0;
            while(i<w1.size() && j<w2.size()) {
                if(w1[i] != w2[j]) {
                    adj[w1[i]-'a'].push_back(w2[j]-'a');
                    totalDiffchars.insert(w1[i]-'a');
                    totalDiffchars.insert(w2[j]-'a');
                    break;
                }
                i++; j++;
            }
            if(j==w2.length() && w1.length() > w2.length()) {
                return "";
            }
        }

        int totalchars = totalDiffchars.size();
        vector<int> indeg(26, -1);
        for(auto &[ch, neigh]: adj) {
            indeg[ch] == -1 ? indeg[ch] = 0 : true;
            for(auto it: neigh) {
                indeg[it]==-1 ? indeg[it]=1 : indeg[it]++;
            } 
        }

        for(auto it: totalDiffchars) {
            if(indeg[it] == -1) {
                indeg[it] = 0;
            }
        }

        queue<int> q;
        for(int i=0 ; i<26 ; i++) {
            if(indeg[i] == 0) {
                q.push(i);
            }
        }

        string topo;
        while(!q.empty()) {
            int ch = q.front();
            q.pop();
            topo.push_back(ch + 'a');

            for(auto it: adj[ch]) {
                indeg[it]--;
                if(indeg[it] == 0) {
                    q.push(it);
                }
            }
        }

        if(topo.length() != totalchars) return "";

        return topo;
    }
};
