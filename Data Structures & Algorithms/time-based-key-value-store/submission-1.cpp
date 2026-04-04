class TimeMap {
    unordered_map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>>& v = mp[key];
        int s = 0, e = v.size()-1;
        string ans = "";
        while(s <= e) {
            int mid = (s+e) / 2;
            int val = v[mid].first;

            if(timestamp == val) {
                ans = v[mid].second;
                s = mid + 1;
            } else if(timestamp < val) {
                e = mid - 1;
            } else {
                // timestamp > val
                ans = v[mid].second;
                s = mid + 1;
            }
        }

        return ans;
    }
};
