class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        // min heap -> {distance, {x, y}}
        priority_queue<
            pair<int, pair<int,int>>, 
            vector<pair<int, pair<int,int>>>, 
            greater<pair<int, pair<int,int>>>
        > pq;
        
        // Step 1: push all points with distance
        for(auto &p : points) {
            int x = p[0];
            int y = p[1];
            int dist = x*x + y*y;
            
            pq.push({dist, {x, y}});
        }
        
        // Step 2: extract k closest
        vector<vector<int>> ans;
        
        while(k--) {
            auto top = pq.top();
            pq.pop();
            
            ans.push_back({top.second.first, top.second.second});
        }
        
        return ans;
    }
};