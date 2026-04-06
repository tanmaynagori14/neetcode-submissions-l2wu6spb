class Solution {
    vector<string> ans;
    unordered_map<string, vector<string>> adj;
    int numOfTickets = 0;

    bool dfs(string currCity, vector<string> &path) {
        path.push_back(currCity);
        if(path.size() == numOfTickets + 1) {
            ans = path;
            return true;
        }

        for(int i=0 ; i<adj[currCity].size() ; i++) {
            string next = adj[currCity][i];

            // remove ticket (mark as used)
            adj[currCity].erase(adj[currCity].begin() + i);

            if(dfs(next, path)) return true;

            // backtrack (restore ticket)
            adj[currCity].insert(adj[currCity].begin() + i, next);
        }

        path.pop_back();
        return false;
    } 
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        numOfTickets = tickets.size();
        for(auto &it: tickets) {
            adj[it[0]].push_back(it[1]);
        }

        for(auto &[key, val]: adj) {
            sort(val.begin(), val.end());
        }

        vector<string> path;
        dfs("JFK", path);

        return ans;
    }
};
