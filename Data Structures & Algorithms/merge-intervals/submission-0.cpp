class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(auto interval: intervals) {
            if(ans.empty()) {
                ans.push_back(interval);
            } else {
                int s = interval[0], e = interval[1];
                if(s <= ans.back()[1]) {
                    // overlapping
                    ans.back()[0] = min(ans.back()[0], s);
                    ans.back()[1] = max(ans.back()[1], e);
                } else {
                    ans.push_back(interval);
                }
            }
        }

        return ans;
    }
};
